#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> d(N);
  for(int i=0;i<N;i++){
    cin >> d[i];
  }
  int ans=0;
  for(int i=1;i<=min(N,K);i++){
    int lim=K-i;
    for(int j=0;j<=i;j++){
      vector<int> opp(i);
      int A=j;
      int B=i-j;
      for(int a=0;a<A;a++){
        opp[a]=d[a];
      }
      for(int b=0;b<B;b++){
        opp[A+b]=d[N-1-b];
      }
      sort(opp.begin(),opp.end());
      for(int l=0;l<lim;l++){
        if(opp[l]>=0){
          break;
        }
        opp[l]=0;
      }
      int current=0;
      for(int k=0;k < i;k++){
        current+=opp[k];
      }
      ans=max(ans,current);
    }
  }
  cout << ans << endl;
}