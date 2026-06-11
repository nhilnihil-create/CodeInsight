#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int N_MAX = 100001;
int main()
{
  int n,t,i,j,res=0;
  int b[N_MAX];
  string s;
  char c[N_MAX];
  cin >> s;
  n=s.size();
  fill(b,b+N_MAX,0);
  for(i=0,t=0;i<n;i++)
    if(s[i]=='x'){
      b[t]++;
    }else{
      c[t]=s[i];
      t++;
    }
  for(i=0;i<(t+1)/2;i++){
    if(c[i]!=c[t-1-i]){
      cout << "-1" << endl;
      return 0;
    }
    res+=abs(b[i]-b[t-i]);
  }
  cout << res << endl;
  return 0;
}