#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  string s;
  cin >> s;
  cout << s[0] << s[1] << s[2] << '8';
  rep(i, 6){
    cout << s[i + 4];
  }
  cout << endl;
}
