#include<iostream>
using namespace std;
typedef long int li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0

int main(){
  int a,b; cin >>a >>b;
  printf("64 64\n");
  char grid[64][64];
  rep(i,64) rep(j,64)
    grid[i][j]=(j<32)?'#':'.';

  rep(i,32)rep(j,16){
    if(--a>0) grid[2*i][2*j]='.';
  }
  rep(i,32)rep(j,16){
    if(--b>0) grid[2*i+1][2*j+33]='#';
  }
  
  rep(i,64){
    rep(j,64) printf("%c",grid[i][j]);
    printf("\n");
  }
}