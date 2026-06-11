#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int f(int x){
  int sum=0;
  while(x){
    sum+=x%10;
    x/=10;
  }
  return sum;
}
int main(){
  int N;
  cin>>N;
  int ans=INF;
  for(int i=1;i<=N-1;i++){
    int A=i,B=N-i;
    chmin(ans,f(A)+f(B));
  }
  cout<<ans<<endl;
  return 0;
}