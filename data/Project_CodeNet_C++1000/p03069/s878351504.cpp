#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i,cnt=0,saisho=0;
  cin>>n;
  char a;
  for(i=0;i<n;i++){
    cin>>a;
    if(a=='#'){
      cnt++;
    }else{
      cnt--;
    }
    saisho=min(saisho,cnt);
  }
  cout<<(n-cnt)/2+saisho;
}