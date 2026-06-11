#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  vector<string> st;
  int n=s.size();
  //set<string> st;
  for(int j=1;j<min(n,5)+1;j++){
    for(int i=0;i<n-j+1;++i){
      st.push_back(s.substr(i,j));
    }
  }

  sort(st.begin(),st.end());
  st.erase(unique(st.begin(),st.end()),st.end());
  cout << st[k-1] << endl;

  return 0;
}
