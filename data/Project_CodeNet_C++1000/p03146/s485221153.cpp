#include<bits/stdc++.h>
using namespace std;
int main(){
  int S;
  cin>>S;
  set<int>st;
  int x=S;
  while(st.count(x)==0){
    st.insert(x);
    if(x%2==0){
      x/=2;
    }
    else{
      x=x*3+1;
    }
  }
  cout<<(st.size()+1)<<endl;
}