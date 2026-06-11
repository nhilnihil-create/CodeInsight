#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int f[(1<<26)+10];
const int oo=1e9;
int main(){
  for(int i=0;i<(1<<26);i++)f[i]=oo;
  string s;
  cin>>s;
  int h=0,fi;
  f[0]=0;
  for(char ch:s){
    h^=( 1<<(ch-'a') );
    fi=1+f[h];
    for(int i=0;i<26;i++){
      int m=(h^(1<<i));
      fi=min(fi,1+f[m]);
    }
    f[h]=min(f[h],fi);
  }
  printf("%d\n",fi); 
  return 0;
}
