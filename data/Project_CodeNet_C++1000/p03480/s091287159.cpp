#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int n=s.size();
  int now=(n+1)/2;
  for(int i=n/2-1;i>=0;i--){
    if(s[i]==s[i+1]&&s[n-i-1]==s[n-i-2])now++;
    else {
      cout<<now<<endl;
      return 0;
    }
  }
  cout<<n<<endl;
}