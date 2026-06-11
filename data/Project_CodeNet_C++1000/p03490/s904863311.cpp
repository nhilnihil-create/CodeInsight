#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100001;

string s;
bitset<18001> b1;
bitset<18001> b2;
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> s;
  int v = 0;
  int len = 0;

  vector<int> m[2];
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'T'){
      m[v].push_back(len);
      len = 0;
      v ^= 1;
    }else{
      len++;
    }
  }
  m[v].push_back(len);

  int x, y;
  cin >> x >> y;
  b1[(m[0].size() ? m[0][0] : 0) + 9000] = 1;
  b2[9000] = 1;
  for(int i = 1;i < m[0].size();i++){
    b1 = (b1 >> m[0][i]) | (b1 << m[0][i]);
  }
  for(int i = 0;i < m[1].size();i++){
    b2 = (b2 >> m[1][i]) | (b2 << m[1][i]);
  }
  if(b1[x + 9000] && b2[y + 9000]){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
  return 0;
}
