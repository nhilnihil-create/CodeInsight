// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  string s;
  cin >> s;
  ll n = s.size();
  bool used[26]={};
  if(n != 26){
    for(auto c:s){
      used[c-'a'] = true;
    }
    for(int i=0;i<26;i++){
      if(!used[i]){
        s += (char)('a'+i);
        break;
      }
    }
    cout << s << endl;
  }else{
    for(int i=n-1;i>=0;i--){
      char c;
      for(c=s[i]+1;c<='z';c++){
        if(used[c-'a']){
          break;
        }
      }
      if(c<='z'){
        for(int j=0;j<i;j++){
          cout << s[j];
        }
        cout << c<<endl;
        return 0;
      }
      used[s[i]-'a'] = true;
    }
    cout << -1<<endl;
  }
}
