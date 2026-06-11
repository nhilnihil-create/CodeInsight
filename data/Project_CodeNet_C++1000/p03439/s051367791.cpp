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
  int N;
  cin>>N;
  
  cout<<0<<endl;
  string S;
  cin>>S;
  VI X(N);
  if(S=="Vacant") return 0;
  if(S=="Male") X[0]=1;
  else X[0]=2;
  
  cout<<N-1<<endl;
  cin>>S;
  if(S=="Vacant") return 0;
  if(S=="Male") X[N-1]=1;
  else X[N-1]=2;
  
  int L=0;
  int R=N-1;
  rep(i,18){
    int mid=(L+R)/2;
    cout<<mid<<endl;
    cin>>S;
    if(S=="Vacant") return 0;
    if(S=="Male") X[mid]=1;
    else X[mid]=2;
    if((mid-L)%2){
      if(X[L]!=X[mid]) L=mid;
      else R=mid;
    }else{
      if(X[L]!=X[mid]) R=mid;
      else L=mid;
    }
  }
  return 0;
}