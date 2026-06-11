#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  s[k-1] = s[k-1]-'A'+'a';
  cout << s << endl;
}
