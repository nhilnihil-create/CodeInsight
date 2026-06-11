#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin >> N >> M;
  int X[M];
  for(int i=0;i<M;i++){
    cin >> X[i];
  }
  sort(X,X+M);
  int sum[M-1];
  for(int i=0;i<M-1;i++){
      sum[i]=X[i+1]-X[i];
  }
  sort(sum,sum+M-1);
  int ans=0;
  if(N<M){
    ans = X[M-1]-X[0];
    for(int j=0;j<N-1;j++){
      ans -= sum[M-2-j];
    }
  }
  cout << ans << endl;
}
