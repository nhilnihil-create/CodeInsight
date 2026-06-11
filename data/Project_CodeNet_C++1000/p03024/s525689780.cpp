#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a,b;
string s,t;

int main() {
  cin >> s;
  int cnt=0;
  for(auto c:s){
    if(c=='o') cnt++;
  }
  cout << (15-(int)s.size()+cnt>=8?"YES":"NO") << endl;
}