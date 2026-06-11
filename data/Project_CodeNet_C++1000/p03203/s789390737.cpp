#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> P;

int H, W, N;
int y[200005], x[200005];
vector<int> A[200005];

void solve(){
  
  int ans = H;
  
  for(int i=0;i<N;i++) A[x[i]].push_back(y[i]);
  
  int pre = 0;
  
  for(int i=1;i<200005;i++){
    
    if( pre < i ) pre = i;
    
    sort( A[i].begin(), A[i].end() );
    
    int idx = -1;
    
    for(int j=0;j<(int)A[i].size();j++){
      
      if( pre > A[i][j] ){
	idx++;
	continue;
      }
      
      if( pre == A[i][j] ){
	idx = j;
	pre++;
      }
      else break;
      
    }
    
    if( idx + 1 < (int)A[i].size() ) ans = min( ans, A[i][idx+1] - 1 );

    pre++;
    
  }
  
  cout<<ans<<endl;
  
}

signed main(){
  
  cin>>H>>W>>N;
  
  for(int i=0;i<N;i++) cin>>y[i]>>x[i];
  
  solve();
  
  return 0;
}
