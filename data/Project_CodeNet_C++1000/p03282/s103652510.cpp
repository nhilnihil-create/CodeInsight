#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  char s[100];
  ll k;
  cin>>s>>k;
  for(int i=0;i<k;i++){
    if(s[i]!='1'){
      printf("%c\n",s[i]);
      return 0;
    }
  }
  cout<<1<<endl;
  return 0;
}