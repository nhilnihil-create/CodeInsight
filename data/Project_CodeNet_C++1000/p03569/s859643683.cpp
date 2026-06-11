#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  
  string s1="";
  rep(i,n){
    if(s[i]!='x') s1=s1+s[i];
  }
  string s2=s1;
  reverse(s2.begin(),s2.end());
  if(s1!=s2){
    puts("-1");
    return 0;
  }
  
  int left=0,right=n-1;
  int ans=0;
  while(left<right){
    if(s[left]==s[right]){
      left++; right--;
    }else{
      ans++;
      if(s[left]=='x') left++;
      else right--;
    }
  }
  cout<<ans<<endl;
}