#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  string s;
  cin >> s;
  int n = s.length();
  int ans = 10000;
  for(int i=0; i<n-2; i++){
    int tmp = s[i]-'0';
    for(int j=1; j<=2; j++){
      tmp *= 10;
      tmp += s[i+j]-'0';
    }
    ans = min(ans, abs(753-tmp));
  }
  cout << ans << endl;
  return 0;
}
