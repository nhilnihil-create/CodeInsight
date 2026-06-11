#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  string ans;
  int n; cin >> n;
  for(int i = 0; i < s.size(); i+=n){
    char c = s.at(i);
    ans.push_back(c);
  }
  cout << ans;
}
    
    
    