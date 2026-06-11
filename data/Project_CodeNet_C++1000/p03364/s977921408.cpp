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
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  VS S(N);
  rep(i,N) cin>>S[i];
  int ans=0;
  rep(i,N) S[i]+=S[i];
  rep(i,N){
    int tmp=1;
    rep(j,N) rep(k,N){
      tmp*=(S[j][k+i]==S[k][j+i]);
    }
    if(tmp) ans++;
  }
  cout<<ans*N<<endl;
}