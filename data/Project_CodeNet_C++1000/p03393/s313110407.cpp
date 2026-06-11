#include <iostream>
#include <set>
using namespace std;
int main(){
  string s;
  cin >> s;

  set<char> st;
  for(int i=0;i<s.size();i++){
    st.insert(s[i]);
  }

  string ans = "";
  if(s.size()==26){
    for(int i=s.size()-1;i>0;i--){
      if(s[i-1] < s[i]){
        char c = s[i];
        for(int j=i;j<s.size();j++){
          if(s[j] > s[i-1] && s[j] < c){
            c = s[j];
          }
        }
        ans = s.substr(0,i-1) + c;
        break;
      }
    }
  }else{
    for(int i=0;i<26;i++){
      auto itr = st.find('a'+i);
      if(itr == st.end()){
        s += 'a'+i;
        ans = s;
        break;
      }
    }
  }

  if(ans == ""){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}
