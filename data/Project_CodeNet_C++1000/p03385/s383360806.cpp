#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  vector<char> s(3);
  for(int i=0; i<3; i++){
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  string ans;
  if(s[0]=='a'&&s[1]=='b'&&s[2]=='c') ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}
