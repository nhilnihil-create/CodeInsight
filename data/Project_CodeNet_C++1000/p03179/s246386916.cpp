#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
template<int mod=hell>
struct mint{
  int m;
  mint():m(0){}
  mint(int m):m((m%mod+mod)%mod){}
  // mint(int m):m(m){}
  mint& fim() { m = (m%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((m+=a.m)>=mod) m-=mod; return *this;}
  mint& operator-=(const mint& a){ if((m+=mod-a.m)>=mod) m-=mod; return *this;}
  mint& operator*=(const mint& a){ (m*=a.m)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return m < a.m;}
  bool operator==(const mint& a)const{ return m == a.m;}
  friend istream& operator>>(istream&i,mint&a){i>>a.m;return i;}
friend ostream& operator<<(ostream&o,const mint&a){o<<a.m;return o;}
};
mint<hell> dp[3001][3001];
mint<hell> pre[3001];
int solve(){
 int n;cin>>n;
 string s;cin>>s;
 bool a[n+1];
 for(int i=0;i<s.length();i++){
 	if(s[i]=='<')a[i+2]=1;
 	else a[i+2]=0;
 }
 dp[1][1]=1;
 for(int i=2;i<=n;i++){
 	pre[0]=0;
    for(int j=1;j<i;j++)pre[j]=pre[j-1]+dp[i-1][j];
 		for(int k=1;k<=i;k++){
 			if(a[i]){
 				dp[i][k]+=pre[k-1];
 			}
 			else{
 				dp[i][k]+=pre[i-1]-pre[k-1];
 			}
 		}
 }
 mint<hell> d;
 for(int i=1;i<=n;i++)d+=dp[n][i];
 	cout<<d<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 