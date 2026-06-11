#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  string s;
  cin>>s;
  ll max=0;

  if(s=="A"||s=="G"||s=="T"||s=="C"){
    cout<<1<<endl;
    return 0;
  }


  rep(i,s.length()-1){
    ll start=i;
    ll tmp=0;

    if(s[start]=='A'||s[start]=='T'||s[start]=='G'||s[start]=='C'){
      tmp++;
      while((s[start+1]=='A'||s[start+1]=='T'||s[start+1]=='G'||s[start+1]=='C')&&start<s.length()){
        start++;
        tmp++;
      }
    }
    if(tmp>max)max=tmp;
  }

  cout<<max<<endl;
  return 0;
}
