#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N,x;
  cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int sum=x;
  int cnt=0;
  for(int i=0;i<N;i++){
    if(sum==0){break;}
    else if(i==0&&a[i]>sum){break;}
    else if(i==N-1&&sum!=a[i]){break;}//余りが少ない個数でも押し付けられる
    else if(sum-a[i]<0){break;}
    else{cnt++;sum-=a[i];}
  }
  cout<<cnt<<endl;
  return 0;  
}