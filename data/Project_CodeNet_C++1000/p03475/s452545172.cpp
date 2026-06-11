#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>C(N-1),S(N-1),F(N-1);
  for(int i=0;i<N-1;i++){
    cin>>C[i]>>S[i]>>F[i];
  }
  for(int i=0;i<N;i++){
    int time=0;
    for(int j=i;j<N-1;j++){
      if(time>=S[j]){
        time=(time+F[j]-1)/F[j]*F[j];
        time+=C[j];
      }
      else{
        time=S[j];
        time+=C[j];
      }
    }
    cout<<time<<endl;
  }
  return 0;  
}