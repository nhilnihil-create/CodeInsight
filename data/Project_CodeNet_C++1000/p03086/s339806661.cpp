#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

bool ATGC(char s){
	if(s == 'A' || s == 'T' || s == 'G' || s == 'C')
      return true;
  	return false;
}
  
void f() {
  string s;
  cin >> s;
  int count;
  int ans = 0;
  int n = s.size();
  forn(i, n){
    count = 0;
    for(int j = i; j < n; j++){
        if(ATGC(s[j])){
              count++;
        }
      	else
          break;
     }
     ans = max(ans, count);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  f();
  return 0;
}