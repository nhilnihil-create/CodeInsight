#include <bits/stdc++.h>
using namespace std;

int vec[110000];
int main(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vec[0]=0;
  for(int i=0;i<s.size()+1;i++){
    if(i==0){
      vec[i+1]=0;
    }
    else{
      if(s[i-1]=='A'&&s[i]=='C'){
        vec[i+1]=vec[i]+1;
      }
      else{
        vec[i+1]=vec[i];
      }
    }
  }
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    cout<<vec[b]-vec[a]<<endl;
  }
}