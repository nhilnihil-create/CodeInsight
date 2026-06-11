#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, Q;
  cin>>N>>Q;
  string S;
  cin>>S;
  int arr[N+1];
  for(int i=0;i<N+1;++i) arr[i] = 0;
  for(int i=1;i<N;++i){
    if(S[i-1]=='A' && S[i]=='C'){
      arr[i+1] = 1;
    }
  }
  for(int i=1;i<=N;++i){
    arr[i] += arr[i-1];
  }
  int l, r;
  int ans[Q];
  for(int i=0;i<Q;++i){
    cin>>l>>r;
    ans[i] = arr[r] - arr[l];
  }
  for(int i=0;i<Q;++i){
    cout<<ans[i]<<endl;
  }
}

