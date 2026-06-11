#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string S;
int cnt_0, cnt_1;

int main(){
  cin >> S;
  rep(i, S.size()){
    if (S[i]=='0') cnt_0++;
    else cnt_1++;
  }
  cout << 2 * min(cnt_0, cnt_1) << endl;
}
