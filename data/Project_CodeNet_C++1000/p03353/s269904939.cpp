#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int main(){
  string s;
  int K;
  cin>>s>>K;
  int n=s.size();
  vector<string> S;
  set<string> st;
  for(int i=0;i<26;i++){
    int num=0;
    char c=(char)('a'+i);
    for(int j=0;j<n;j++){
      if(s.at(j)==c){
        string str="";
        for(int k=j;k<j+K&&k<n;k++){
          str.push_back(s.at(k));
          if(st.count(str)==0){
            S.push_back(str);
            st.insert(str);
          }
        }
      }
    }
    if(S.size()>=K){
      break;
    }
  }
  sort(S.begin(),S.end());
  cout<<S.at(K-1)<<endl;
}
