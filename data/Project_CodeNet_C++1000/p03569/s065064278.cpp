#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  string S;
  cin>>S;
  string SS;
  rep(i,S.size()) if(S[i]!='x') SS+=S[i];
  string RR=SS;
  reverse(all(SS));
  if(SS!=RR){
    cout<<-1<<endl;
    return 0;
  }
  VI X(SS.size()+1);
  int P=0;
  int cnt=0;
  rep(i,S.size()){
    if(S[i]=='x'){
      cnt++;
    }else{
      X[P]=cnt;
      P++;
      cnt=0;
    }
  }
  X[P]=cnt;
  int ans=0;
  rep(i,X.size()/2) ans+=abs(X[i]-X[X.size()-1-i]);
  cout<<ans<<endl;
}