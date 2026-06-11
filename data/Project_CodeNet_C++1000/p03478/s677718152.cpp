#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,A,B;
  long ans = 0;
  cin >> N >> A >> B;
  for(int i=1;i<=N;++i){
    int sum = 0;
    string s;
    s = to_string(i);
    for(int j=0;j<s.size();++j){
      sum += s.at(j) - '0';
    }
    if(sum >= A && sum <= B) ans += i;
  }
    cout << ans << endl;
    return 0;
}
