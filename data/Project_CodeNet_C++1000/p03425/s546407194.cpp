#include <bits/stdc++.h>
using namespace std;
int main(){
  int64_t n, ct[5]={0}, ans=0;
  cin >> n;
  string s;
  for(int i=0; i<n; i++){
    cin >> s;
    if(s[0]=='M')
      ct[0]++;
    else if(s[0]=='A')
      ct[1]++;
    else if(s[0]=='R')
      ct[2]++;
    else if(s[0]=='C')
      ct[3]++;
    else if(s[0]=='H')
      ct[4]++;
  }
    for(int i=0; i<5; i++)
      for(int j=i+1; j<5; j++)
	for(int k=j+1; k<5; k++)
	  ans+=ct[i]*ct[j]*ct[k];
    cout << ans;
    return 0;
  }