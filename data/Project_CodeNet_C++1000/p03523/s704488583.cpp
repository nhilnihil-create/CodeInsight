#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

string s;

int main() {
  cin >> s;
  string t="AKIHABARA";
  rep(i,9){
    if(s[i]!=t[i]) 
    s.insert(i,"A");
  }
  cout << (s==t?"YES":"NO") << endl;
}