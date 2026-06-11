#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;
    V<int> k(q);
    for(int i=0;i<q;i++)cin>>k[i];
    for(int i=0;i<q;i++){
          ll d=0,m=0,dm=0,ans=0;
          queue<char> que;
          for(int j=0;j<n;j++){
              if(que.size()>=k[i]){
                  char c=que.front();que.pop();
                  if(c=='D'){
                      dm-=m;
                      d--;
                  }
                  else if(c=='M'){
                      m--;
                  }
              }
              char c=s[j];
              que.push(c);
              if(c=='C')ans+=dm;
              else if(c=='M'){
                  m++;
                  dm+=d;
              }
              else if(c=='D'){
                    d++;
              }
          }
          cout<<ans<<endl;
    }
}