#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int f(int x){
  int cnt=0;
  for(int i=1;i<=x;i++){
    if(x%i==0){cnt++;}
  }
  return cnt;
}

int main() {
  int N;
  cin>>N;
  int cnt=0;
  for(int i=1;i<=N;i++){
    if(i%2!=0&&f(i)==8){cnt++;}
  }
  cout<<cnt<<endl;
  return 0;  
}