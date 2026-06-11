#include <bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin>>s;
  int n=s;
  set<int> st;
  while(st.count(n)==0){
    st.insert(n);
    if(n%2==0) n/=2;
    else n=3*n+1;
  }
  cout<<(st.size()+1)<<endl;
}
