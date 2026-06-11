#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
typedef long int li;


int fact_ord(int b,int n){
  int ret=0;
  while(n){
    n/=b;
    ret+=n;
  }
  return ret;
}

int main(){
  int n; cin >>n;
  int primes[]=  {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47} ;
  int thresh[5]= {74,24,14,4,2} ;
  int array[5]=  {0,0,0,0,0};
  for(int x:primes){
    int a=fact_ord(x,n);
    rep(i,5){
      if(a>=thresh[i]) array[i]++;
    }
  }
  if(df) {
    for(int x:array) cout << x << " ";
    cout << "\n";
  }
  int ans=0;
  ans+=array[0];
  ans+=array[1]*(array[4]-1);
  ans+=array[2]*(array[3]-1);
  ans+=array[3]*(array[3]-1)/2*(array[4]-2);
  printf("%d\n",ans);
}
