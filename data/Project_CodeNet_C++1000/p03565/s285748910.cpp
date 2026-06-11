

#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;


 int main(){

  string s,t;
  cin>>s>>t;

  int n = s.length(); int k = t.length();
  int st = -1;

  for(int i=0;i<=n-k;i++)
  {

      bool flag = true;

      for(int j=0;j<k;j++){
         if(s[i+j] != t[j] && s[i+j] != '?'){
            flag  = false;
            break;
         }
      }

      if(flag  == true)
        st = i;

  }

  if(st == -1)
       cout<<"UNRESTORABLE\n";
  else{
      for(int i=st;i<st+k;i++){
        s[i] = t[i-st];
        for(int i=0;i<n;i++){
            if(s[i] == '?')
            s[i] = 'a';
      }
  }
     cout<<s<<endl;

  }

 return 0;
 }