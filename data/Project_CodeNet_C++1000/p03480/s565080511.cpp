#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int n=s.size();
  int ans=(n+1)/2;
  if(n%2==0){
    for(int i=0;i<n/2;i++){
      if(s[n/2-1-i]==s[n/2]&&s[n/2+i]==s[n/2])ans++;
      else{
        cout<<ans<<endl;
        return 0;
      }
    }
    cout<<n<<endl;
    return 0;
  }
  else{
    for(int i=0;i<n/2;i++){
      if(s[n/2-1-i]==s[n/2]&&s[n/2+1+i]==s[n/2])ans++;
      else{
        cout<<ans<<endl;
        return 0;
      }
    }
    cout<<n<<endl;
  }
}
  