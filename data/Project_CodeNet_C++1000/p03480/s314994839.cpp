#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
using namespace std;


typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
  string s;
  cin >> s;
  char before = s[0];
  int cnt = 0;
  int itr = 0;
  int l = s.length() / 2;
  int r = s.length() / 2;
  if(s.length() % 2 == 0){
    l--;
  }

  int ans = s.length() / 2;
  int num = s[l];
  for(int i = 0; i < s.length(); ++i){
    if(s[l] != s[r] || s[l] != num) break;
    ans++;
    l--;
    r++;
  }

  cout << ans << endl;
}
