#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;cin>>n>>q;
  string s;cin>>s;
  vector<int>ans(n+3,0);
  for(int i=1;i<n;i++){
    if(s.at(i-1)=='A'&&s.at(i)=='C'){
      ans.at(i+1)=ans.at(i)+1;
    }
    else ans.at(i+1)=ans.at(i);
  }
  int l,r;
  int tmp;
  for(int i=0;i<q;i++){
    cin>>l>>r;
    tmp=ans.at(r)-ans.at(l-1);
    if(l>=2&&(s.at(l-2)=='A'&&s.at(l-1)=='C'))tmp--;
    cout <<tmp<<endl;
  }
}