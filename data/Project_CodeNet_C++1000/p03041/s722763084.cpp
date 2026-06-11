#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    char c;
    c = tolower(S[K - 1]);
    S[K - 1] = c;
    cout << S << endl;
  return 0;
}
