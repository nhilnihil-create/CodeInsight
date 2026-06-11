#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,k=20; 
 	cin>>n;
    while(!(n&(1<<k))) k--;
    printf("%d %d\n", k+1, 2*k+__builtin_popcount(n)-1);
    for(i=0; i<k; i++){
      printf("%d %d %d\n", i+1, i+2, 0);
      printf("%d %d %d\n", i+1, i+2, 1<<i);
    }
    int a=1<<k;
    for(i=k-1; i>=0; i--){
      if((1<<i)&n){
        printf("%d %d %d\n", i+1, k+1, a);
        a+=1<<i;
      }
    }
}