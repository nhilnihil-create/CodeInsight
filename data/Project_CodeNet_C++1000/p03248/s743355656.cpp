#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define chmin(x,y) if(x>y)x=y
#define chmax(x,y) if(x<y)x=y
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
const ll inf=1001001001001001;
const int Inf=1001001001;
const int mod=1000000007;
int main(){
    string s;cin>>s;
    ll n=s.size();
    if(s[n-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }
    rep(i,n/2){
        if(s[i]!=s[n-i-2]){
            cout<<-1<<endl;
            return 0;
        }
    }
  	if(s[0]=='0'){
      cout<<-1<<endl;
      return 0;
    }
    cout<<1<<' '<<2<<endl;
    int a=2,b;
    rep(i,n-2){
        if(s[i]=='0')cout<<b<<' '<<i+3<<endl;
        else{
            cout<<a<<' '<<i+3<<endl;
          	b=a;
            a=i+3;
        }
    }
}