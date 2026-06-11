#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

int main() {
  int n,sum=0,saisyob=0,saigoa=0,dottimo=0;
  cin >> n;
  string s[n];
  r(i,n){
    cin>>s[i];
    r(j,s[i].length()-1){
      if(s[i][j]=='A'&&s[i][j+1]=='B')sum++;
    }
    if(s[i][0]=='B'&&s[i][s[i].length()-1]=='A')dottimo++;
    else{
    if(s[i][0]=='B')saisyob++;
    if(s[i][s[i].length()-1]=='A')saigoa++;
    }
  }
  if(saisyob+saigoa==0)cout<<max(dottimo-1,0)+sum<<endl;
  else cout<<sum+dottimo+min(saisyob,saigoa)<<endl;
}