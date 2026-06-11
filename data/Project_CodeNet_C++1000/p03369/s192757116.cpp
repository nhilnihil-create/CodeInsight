#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  string s;
  cin >> s;
  int cnt = 0;
  for(int i=0; i<s.length(); i++){
    if(s[i]=='o') cnt++;
  }
  cout << 700+100*cnt << endl;
  return 0;
}
