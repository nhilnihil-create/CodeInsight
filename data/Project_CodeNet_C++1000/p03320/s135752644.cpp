#include<bits/stdc++.h>
using namespace std;
#define mx 100005

int t, u;
int main(){
  scanf("%d", &u);
  for(t = 0; t < 18;){
    printf("%d\n", (t%9+1)*(t/9?10:1)+(t/9?9:0));
    if(++t == u) return 0;
  }
  for(int i = 0; i < 15; i++){
    for(int j = 1; j < 10; j++){
      for(int k = 0; k < 10; k++){
        for(int l = 0; l < 10; l++){
          if((j*100+k*10+l+1) <= (i*9+j+k+l)*(l-9?1:k-9?10:l-9?100:1000)){
            printf("%d%d%d", j, k, l);
            for(int m = 0; m < i; m++) printf("9");
            puts("");
            if(++t == u) return 0;
          }
        }
      }
    }
  }
}