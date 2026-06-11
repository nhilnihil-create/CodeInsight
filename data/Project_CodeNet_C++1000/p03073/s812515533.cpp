#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  vector<char>st(s.size());
  for(int i=0;i<s.size();i++){
    st.at(i)=s.at(i);
  }
  int cnt=0;
  for(int i=0;i<s.size()-1;i++){
    if(st.at(i)==st.at(i+1)){
      if(st.at(i+1)=='0'){
        st.at(i+1)='1';
      }
      else{
        st.at(i+1)='0';
      }
      cnt++;
    }
  }
  cout << cnt << endl;
}
