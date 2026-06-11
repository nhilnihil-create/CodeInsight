#include<iostream>
#include<string>
using namespace std;
int main(){
  
  string s;
  cin >> s;
  long long ans = 0;
  long long cnt = 0;
  for(long long i=0; i<(long long)s.size(); i++){
    if(s[i] == 'W'){
      ans += i - cnt;
      cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}
