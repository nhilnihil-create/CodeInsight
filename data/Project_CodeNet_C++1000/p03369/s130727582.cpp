#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int ans = 700;
  rep(i, 3){
    char s;
    cin >> s;
    if(s == 'o') ans += 100;
  }
  cout << ans << endl;
}