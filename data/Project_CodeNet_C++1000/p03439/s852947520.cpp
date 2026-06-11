#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int mn=0,mx=N;
  printf("0\n");
  fflush(stdout);
  string s;
  cin>>s;
  if(s=="Vacant")
    return 0;
  while(mx-mn>1){
    int n=(mn+mx)/2;
    printf("%d\n",n);
    fflush(stdout);
    string S;
    cin>>S;
    if(S=="Vacant")
      return 0;
    if((S==s && (n-mn)%2==0) || (S!=s && (n-mn)%2==1))
      mn=n,s=S;
    else
      mx=n;
  }
  printf("%d\n",mx);
  fflush(stdout);
  string S;
  cin>>S;
  if(S!="Vacant"){
    printf("%d\n",mn);
    fflush(stdout);
  }
  return 0;
}