#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  string s; cin >> s;
  set<char> SET;
  for(lint i = 0; i < s.size(); i++) SET.insert(s[i]);
  lint N = s.size();
  if(N == 26){
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
      cout << -1 << endl;
      return 0;
    }
    else{
      int id = -1;
      for(lint i = N - 2; i >= 0; i--){
        if(s[i] < s[i + 1]){
          id = i; break;
        }
      }
			string t = s.substr(0, id);
			int idx2 = id + 1; 
			for(int i = id + 1;i < s.length(); i++){
				if(s[i] < s[idx2] && s[i] > s[id]){
					idx2 = i;
				}
			}
			t += s[idx2];
			cout << t << endl;
		}
  }
  else{
    for(int i = 0; i < 26; i++){
      if(!SET.count(char(i + 'a'))){
        s += (i + 'a');
        break;
      }
    }
    cout << s << endl;
  }
}