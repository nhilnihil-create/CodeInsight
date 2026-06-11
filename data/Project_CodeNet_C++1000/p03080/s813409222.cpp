#include<bits/stdc++.h>
#define rap(i,n) for(int i=0;i<n;++i)
using namespace std;
signed main(){
  string s;
  int n,r=0,b=0;
  cin>>n>>s;
  for(int i=0;i<n;i++){
	 if(s[i]=='R'){
		r++;
     }else if(s[i]=='B'){
       b++;
     }
  }
  if(r>b){
    cout<<"Yes\n";
  }else{
    cout<<"No\n";
  }
return(0);
}