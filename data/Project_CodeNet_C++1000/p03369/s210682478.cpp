#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    string s; cin >> s;
  int ans = 700;
  for(int i=0; i<3; i++){
  	if(s[i] == 'o') ans += 100;
  }
  cout << ans << endl;
    return 0;
}