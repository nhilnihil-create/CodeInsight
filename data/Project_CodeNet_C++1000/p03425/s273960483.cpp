#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;
int main(){
  ll n;
  cin>>n;
 ll M=0; ll A=0; ll R=0; ll C=0; ll H=0;
  rep(i,n){
    string s;
    cin>>s;
    if(s[0]=='M') M++;
else if(s[0]=='A') A++;
else if(s[0]=='R') R++;
else if(s[0]=='C') C++;
else if(s[0]=='H') H++;
  }
 cout<<M*A*R+M*A*C+M*A*H+M*R*C+M*R*H+M*C*H+A*R*C+A*R*H+A*C*H+R*C*H<<endl;
return 0;
}