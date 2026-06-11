#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  int K[N];
  int A[N][M];
  int count[M];
  for(int i=0;i<M;i++) count[i]=0;
  for(int i=0;i<N;i++){
    cin >> K[i];
    for(int j=0;j<K[i];j++){
      cin >> A[i][j];
      count[A[i][j]-1]++;
    }
  }
  int ans=0;
  for(int i=0;i<M;i++){
    if (count[i]==N) ans++;
  }
  cout << ans;
}
