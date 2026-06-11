#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A_cnt=0,B_cnt=0,BA_cnt=0,sum=0;

  for(int i=0;i<N;++i){
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]=='B' && s[n-1]=='A') ++BA_cnt;
    else if(s[0]=='B') ++B_cnt;
    else if(s[n-1]=='A') ++A_cnt;
    for(int i=0;i<n-1;++i){
      if(s[i]=='A' && s[i+1]=='B') ++sum;
    }
  }

  if(A_cnt+B_cnt>0) cout<<sum+BA_cnt+min(A_cnt,B_cnt)<<endl;
  else{
    if(BA_cnt>0) cout<<sum+BA_cnt-1<<endl;
    else cout<<sum<<endl;
  }
  
}
