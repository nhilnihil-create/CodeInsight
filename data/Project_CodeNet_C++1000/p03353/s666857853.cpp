#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int k;cin>>k;
  int n=S.size();
  set<string> st;
  for(int j=1;j<=k;j++){
    for(int i=j-1;i<n;i++){
      string s="";
      for(int t=i+1-j;t<=i;t++){
        s+=S[t];
      }
      st.insert(s);
    }
  }
  for(int i=0;i<k-1;i++){
    string s=*begin(st);
    st.erase(s);
  }
  cout<<*begin(st)<<endl;
}