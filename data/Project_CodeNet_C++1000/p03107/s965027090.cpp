#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using namespace std;

int main(){
  string s;cin>>s;
  stack<int> st;
  int sum=0;
  rep(i,s.size()){
    if(st.empty())st.push(s[i]);
    else if(st.top()!=s[i])sum++,st.pop();
    else st.push(s[i]);
  }
  cout<<sum*2<<endl;
}