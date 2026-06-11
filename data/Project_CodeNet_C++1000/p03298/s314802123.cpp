#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int dy[4]={0,1,-1,0};
int dx[4]={1,0,0,-1};

int main(){
    int n;cin>>n;n*=2;
    string s;cin>>s;
    int half=n/2;
    map<pair<string,string>,int> left,right;
    rep(i,1<<half){
        string a,b;
        rep(j,half){
            if(i&(1<<j)){
                a+=s[j];
            }
            else{
                b+=s[j];
            }
        }
        left[make_pair(a,b)]++;
        //cout<<a<<" "<<b<<endl;
    }
    rep(i,1<<half){
        string a,b;
        rep(j,half){
            if(i&(1<<j)){
                a=s[j+half]+a;
            }
            else{
                b=s[j+half]+b;
            }
        }
        right[make_pair(a,b)]++;
        //cout<<a<<" "<<b<<endl;
    }
    ll ans=0;
    for(auto au:left){
        ans+=1ll*au.second*right[au.first];
    }
    cout<<ans<<endl;
}