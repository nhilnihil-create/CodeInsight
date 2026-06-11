#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int cnt = 0;
int n;

void dfs(string num){
  if(stoll(num) <= n){
    bool three = false, five = false, seven = false;
    rep(i, num.length()){
      if(num[i] == '3') three = true;
      if(num[i] == '5') five = true;
      if(num[i] == '7') seven = true;
    }
    if(three && five && seven){
      cnt++;
    }
 	dfs(num + "3");
    dfs(num + "5");
    dfs(num + "7");
  }
}

int main(){
  cin >> n;
  dfs("3");
  dfs("5");
  dfs("7");
  cout << cnt << endl;
  return 0;
}
  