#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  long long cnt[5] = {};
  string tag = "MARCH";
  for(int i = 0; i < N; ++i){
    string s;
    cin >> s;
    auto id = tag.find(s[0]);
    if(id == string::npos) continue;
    ++cnt[id];
  }
  long long ans = 0;
  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < i; ++j){
      for(int k = 0; k < j; ++k){
        ans += cnt[i]*cnt[j]*cnt[k];
      }
    }
  }
  cout << ans << endl;
}
