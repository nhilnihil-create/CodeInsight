#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N,x;
  cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int sum=0;
  for(int i=0;i<N;i++){
    if(x>=a[i]){
      if(i<N-1){sum++;x-=a[i];}
      else {
        if(x==a[i]){sum++;x-=a[i];}
        else{x-=a[i];}
      }
    }
    else{break;}
  }
  cout<<sum<<endl;
  return 0;  
}