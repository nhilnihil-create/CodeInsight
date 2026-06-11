#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;cin>>s>>t;
  vector<char >a,b;
  for(int i=0;i<s.size();i++)a.push_back(s[i]);
  for(int i=0;i<t.size();i++)b.push_back(t[i]);
  sort(a.begin(),a.end());
  sort(b.rbegin(),b.rend());
  
  int pos=-1;
 // cout<<s<<'\n'<<t<<'\n';
  for(int i=0;i<s.size() && i<t.size();i++){
   //   cout<<a[i]<<' '<<b[i]<<'\n';
  	if(a[i]<b[i]){pos=1;break;}
    if(a[i]>b[i]){pos=0;break;}
  }
  if(pos==1)cout<<"Yes\n";
  else if(pos==0) cout<<"No\n";
  else{
      if(s.size()>=t.size())cout<<"No\n";
      else cout<<"Yes\n";
      
  }
  
}