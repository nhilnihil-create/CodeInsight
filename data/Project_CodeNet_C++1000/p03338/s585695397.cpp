//Cut and Count

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) int n;cin>>n;vector<int>a(n);rep(i,0,n)cin>>a[i]
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
#define cout15(a) printf("%.15f\n",a)
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<int,string> p;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    set<char>a,b;
    rep(i,1,n-1){
        set<char>a,b;
        a.clear();b.clear();
        rep(j,0,i){
            a.insert(s[j]);
        }
        rep(j,i,n){
            b.insert(s[j]);
        }
        int c=0;
        irep(i,b){
            if(a.find(*i)!=a.end())c++;
        }
        ans = max(ans,c);
    }
    cout<<ans<<nnn;
    return 0;
}