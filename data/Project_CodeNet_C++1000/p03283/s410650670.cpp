#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vc=vector<char>;
using vd=vector<double>;
using vp=vector<P>;
using vs=vector<string>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////

//abc09d;present

struct Seg {
private:
    int n;
    vector<int> node;

public:
    // 元配列 v をセグメント木で表現する
    Seg(vector<int> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[2*i+1]+ node[2*i+2];
    }
    void update(int a,int b){
        a+=n-1;
        node[a]+=b;
        while(a>0){
            a=(a-1)/2;
            node[a]=node[2*a+1]+node[2*a+2];
        }
    }
    int query_sub(int a,int b,int k,int l,int r){
        if(r<=a||b<=l){
            return 0;
        }
        else if(a<=l&&r<=b){
            return node[k];
        }
        else {
            int res1=query_sub(a,b,k*2+1,l,(l+r)/2);
            int res2=query_sub(a,b,2*k+2,(l+r)/2,r);
            return res1+res2;
        }
    }
    int getnum(int a,int b){return query_sub(a,b,0,0,n);}

    
};
using mt=tuple<int,int,int>;
bool cmp(mt a, mt b){
    if(get<0>(a)!=get<0>(b))return get<0>(a)<get<0>(b);
    return get<2>(a)<get<2>(b);
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    
    vector<tuple<int ,int, int>> ins(m+q);
    rep(i,m){
        int l,r;
        cin>>l>>r;
        --l,--r;
        get<0>(ins[i])=r;
        get<1>(ins[i])=l;
        get<2>(ins[i])=-1;
    }
    rep(i,q){
        int l,r;
        cin>>l>>r;
        --l,--r;
        
        get<0>(ins[m+i])=r;
        get<1>(ins[m+i])=l;
        get<2>(ins[m+i])=i;
    }
    sort(all(ins),cmp);
    vi ans(q);
    Seg seg(vi (n,0));
    rep(i,m+q){
        int l=get<1>(ins[i]);
        int r=get<0>(ins[i]);
        int a=get<2>(ins[i]);
        if(a>=0){
            int res=seg.getnum(l,r+1);
            ans[a]=res;
        }
        else seg.update(l,1);
    }
    rep(i,q)cout<<ans[i]<<endl;
    return 0;
}