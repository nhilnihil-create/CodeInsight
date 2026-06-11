#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
string ans[111][111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a,b;cin>>a>>b;
  for(int i=0;i<100;i++){
    for(int j=0;j<50;j++){
      ans[i][j] = '#';
    }
  }
  for(int i=0;i<100;i++){
    for(int j=50;j<100;j++){
      ans[i][j] = '.';
    }
  }
  ll cnt = 1;
  for(int i=0;i<100;i++){
    for(int j=i%2+1;j<49;j+=3){
      if(cnt == a){break;}
      ans[i][j] = '.';
      cnt++;
    }
    if(cnt == a)break;
  }
  cnt = 1;
  for(int i=0;i<100;i++){
    for(int j=51+i%2;j<100;j+=3){
      if(cnt == b){break;}
      ans[i][j] = '#';
      cnt++;
    }
    if(cnt == b)break;
  }
  cout<<100<<" "<<100<<endl;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++)
      cout<<ans[i][j];
    cout<<endl;
  }
  return 0;
}
