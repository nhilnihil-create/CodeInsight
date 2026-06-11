#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  string S;
  cin >> N >> S;

  int red = 0;
  for(int i = 0;i < N;i++) {
    if(S.at(i) == 'R') red++;
  }

  if(red > N/2) cout << "Yes" << endl;
  else cout << "No" << endl;
}

