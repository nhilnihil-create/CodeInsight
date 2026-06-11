#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  int f[26] = {};
  for(int i=0; i<n-1; i++){
    f[s[i]-'a']++;
    int b[26] = {};
    for(int j=i+1; j<n; j++){
      b[s[j]-'a']++;
    }
    int tmp = 0;
    for(int k=0; k<26; k++){
      if(f[k]&&b[k]) tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
