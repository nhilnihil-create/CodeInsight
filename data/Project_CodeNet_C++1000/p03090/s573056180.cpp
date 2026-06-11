#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int n, i;
  cin >> n;

  if(n==3){
    printf("2\n");
    printf("1 3\n");
    printf("2 3\n");
  }
  else if(n==4){
    printf("4\n");
    printf("1 2\n");
    printf("1 3\n");
    printf("4 2\n");
    printf("4 3\n");
  }
  else if(n%2){
    printf("%d\n",(n/2)*4);

    printf("%d %d\n",n,1);
    printf("%d %d\n",n,n-1);
    for(i=1;i<n/2;i++){
      printf("%d %d\n",i,i+1);
      printf("%d %d\n",i,n-i-1);
      printf("%d %d\n",n-i,i+1);
      printf("%d %d\n",n-i,n-i-1);
    }
    printf("%d %d\n",n/2,n);
    printf("%d %d\n",n/2+1,n);
  }
  else{
    printf("%d\n",(n/2)*4);

    for(i=1;i<n/2;i++){
      printf("%d %d\n",i,i+1);
      printf("%d %d\n",i,n-i);
      printf("%d %d\n",n-i+1,i+1);
      printf("%d %d\n",n-i+1,n-i);
    }
    printf("%d %d\n",n/2,1);
    printf("%d %d\n",n/2,n);
    printf("%d %d\n",n/2+1,1);
    printf("%d %d\n",n/2+1,n);
  }

  return 0;
}
