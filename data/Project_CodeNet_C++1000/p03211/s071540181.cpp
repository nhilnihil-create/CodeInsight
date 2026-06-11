
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//ctoiは自分で実装できる
int ctoi(char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
    string s;
    cin >> s;
    int ans = 999;
    int n = s.size()-2;
    for(int i=0; i<n; i++){
        int temp = 100*(ctoi(s[i]))+10*(ctoi(s[i+1]))+(ctoi(s[i+2]));
        ans = min(ans, abs(753-temp));
    }
    cout << ans << endl;
}