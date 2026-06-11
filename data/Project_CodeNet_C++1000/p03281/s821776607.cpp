#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  int ans=0;
  int cnt=0;
  int temp=0;
  for(int j=1;j<=N;j+=2){
    vector<int> v;
    for(int i=1;i*i<=j;i++){
      if(j%i==0){
        v.push_back(i);
        if(i!=(j/i)) v.push_back(j/i);
      }
    }
    if(v.size()==8){
      cnt++;
    }
  }
  cout << cnt << endl;
}
