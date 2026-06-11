#include<bits/stdc++.h>
using namespace std;
int main(){
  long a,b,k; cin >> a >> b >>k;
  for(int i = 0; i < k; i++){
    if(i % 2 == 0){
      if(a % 2 == 1)a--;
      b += a/2;
      a =max(a/2,0l);
    }
    else{
      if(b % 2 == 1) b--;
      a += b/2;
      b = max(b/2,0l);
    }
    //printf("%d %d\n",a,b);
  }
  printf("%d %d\n",a,b);
}