#include <bits/stdc++.h>
using namespace std;

int main() {
int s;
int ans = 1;

cin >> s;
vector<bool> vec(2000000);
while(1){
  if(!vec.at(s)){
    vec.at(s) = true;
  }else{
    cout << ans << endl;
    return 0;
  }
  if(s%2 == 0){
    s = s/2;
    ans += 1;
  }else{
    s = 3*s + 1;
    ans += 1;
  }
}
  return 0;
}
