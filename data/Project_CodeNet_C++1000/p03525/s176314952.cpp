#include<bits/stdc++.h>
using namespace std;using ll=long long;using vi=vector<int>;using vvi=vector<vi>;using vl=vector<ll>;using vvl=vector<vl>;using P=pair<int,int>;using PL=pair<ll,ll>;using vp=vector<P>;using vpl=vector<PL>;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/2;constexpr int INF=inf<int>,MOD=1000000007;constexpr ll LINF=inf<ll>;
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...)_ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n)for(int i=n-1;i>=0;--i)
#define REPA(i,v)REP(i,(v).size())
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define bit(n)(1ll<<(n))
#define F first
#define S second
#define endl '\n'
#define cho(n,a,b)cout<<((n)?a:b)<<endl
void YES(int n){cho(n,"YES","NO");}void Yes(int n){cho(n,"Yes","No");}void Poss(int n){cho(n,"Possible","Impossible");}
void _print(ostream&){}template<class T,class...U>void _print(ostream&s,const T&t,const U&...u){s<<t<<(sizeof...(u)?' ':'\n');_print(s,u...);}
template<class...T>void print(const T&...t){_print(cout,t...);}template<class...T>void dprint(const T&...t){_print(cerr,t...);}
#ifndef LOCAL
struct osd{template<class T>osd&operator<<(const T&t){return*this;}};osd cer_;
#define dprint(...)
#define cerr cer_
#endif
template<class T>bool chmax(T&a,const T&b){bool x=a<b;x?a=b:b;return x;}template<class T>bool chmin(T&a,const T&b){bool x=a>b;x?a=b:b;return x;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<<p.F<<' '<<p.S;}
template<class T,class U>istream&operator>>(istream&i,pair<T,U>&p){return i>>p.F>>p.S;}
//template<class T>class iterable{template<class U>static auto c(U v)->decltype(all(v),true_type());static false_type c(...);public:const static bool value=decltype(c(declval<T>()))::value;};
//template<class T,typename=enable_if_t<iterable<T>::value>>ostream&operator<<(ostream&o,const T&v){for(auto&&i:v)o<<i<<' ';return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(T&j:v)i>>j;return i;}
template<class T>vector<T>&operator<<(vector<T>&v,const T&t){v.push_back(t);return v;}
template<class T>set<T>&operator<<(set<T>&v,const T&t){v.insert(t);return v;}
template<class T>multiset<T>&operator<<(multiset<T>&v,const T&t){v.insert(t);return v;}

void bdmp(int a){
    for(int i=1;i<1<<24;i<<=1)cerr<<!!(a&i);
    cerr<<endl;
}

set<int> a;

int dfs(int stat, set<int>::const_iterator pos){
    if(pos==a.end()){
        int mi=INF;
        if(stat==1)return 0;
        bdmp(stat);
        REP(i,24){
            if(stat&bit(i)){
                int ii=i;
                cerr<<string(i,' ')<<'^'<<endl;
                ++i;
                while(i<24 && !(stat&bit(i)))i++;
                dprint(i-ii);
                if(i-ii<=12)
                    chmin(mi, i-ii);
                --i;
            }
        }
        return mi;
    }else{
        auto nx=next(pos);
        if(*pos==0 || *pos==12){
            dprint("!");
            bdmp(stat);
            dprint(*pos);
            if(stat&bit(*pos))return 0;
            return dfs(stat | bit(*pos), nx);
        }
        int ma=0;
        if(!(stat&bit(*pos)))   chmax(ma, dfs(stat | bit(*pos), nx));
        if(!(stat&bit(24-*pos)))chmax(ma, dfs(stat | bit(24-*pos), nx));
        return ma;
    }
}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int cnt[13]={};
    REP(i,n){
        int d;
        cin>>d;
        cnt[d]++;
        /*
        if(d!=0 && a.find(d)!=a.end()){
            a.insert(24-d);
        }else{
            a.insert(d);
        }*/
    }
    REP(i,13){
        if(i==0 && cnt[i]){
            print(0);
            return 0;
        }else if(cnt[i]>2){
            print(0);
            return 0;
        }else if(cnt[i]==2){
            if(i==12){
                print(0);
                return 0;
            }
            a.insert(24-i);
            a.insert(i);
        }else if(cnt[i]==1){
            a.insert(i);
        }
    }
    for(auto&&x:a)cerr<<x;cerr<<endl;
    print(dfs(1, a.begin()));
}
