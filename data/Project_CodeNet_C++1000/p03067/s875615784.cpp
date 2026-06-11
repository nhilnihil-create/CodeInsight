#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // Tenka1 Programmer Beginner Contest 2019 A - On the Way
  int A, B, C; cin >> A >> B >> C;
  if((A < C && C < B) || (B < C && C < A)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
