#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  int A,B;
  int K;
  cin >> A >> B >> K;


  int ans=0;
  int cnt=0;
  int temp=0;
  int c=min(A,B);
  int d=max(A,B);
    vector<int> v;
    for(int i=1;i<=c;i++){
      if(c%i==0 && d%i==0){
        v.push_back(i);
      }
    }

  cout << v[v.size()-K] << endl;
}
