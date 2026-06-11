#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)

int main() {
  int N;
  cin >> N;
  vector<char> S(N);
  string color = "Three";
  rep(i,N) {
    cin >> S[i];
    if(S[i] == 'Y') {
      color = "Four";
      break;
    }
  }
  cout << color << endl;
}
