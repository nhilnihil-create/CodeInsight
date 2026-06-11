#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#ifdef BTK
#define DEBUG if(1)
#else
#define DEBUG if(0)
#endif

#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
const string ok = "Yes";
const string ng = "No";

const int inf=1145141919;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int bit=0;
    unordered_map<int,int> x;
    x[bit]=0;
    REP(i,n){
        int t=s[i]-'a';
        bit^=(1<<t);
        REP(c,26){
            if(x.count(bit^(1<<c))){
                if(x.count(bit)==0)
                    x[bit]=inf;
                chmin(x[bit],x[bit^(1<<c)]+1);
            }
        }
    }
    
    cout<<max(x[bit],1)<<endl;
    
    return 0;
}
