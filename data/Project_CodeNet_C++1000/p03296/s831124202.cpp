#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N; cin >> N;
  int cnt = 0, prv = -1, ans = 0;
  for(int i = 0; i < N; i++){
    int tmp; cin >> tmp;
    if(prv == tmp) cnt++;
    else{
      ans += cnt/2;
      cnt = 1;
    }
    prv = tmp;
  }
  ans += cnt/2;
  cout << ans << endl;
}