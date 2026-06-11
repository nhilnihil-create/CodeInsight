#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  int n,m;
 
  scanf("%d %d",&n,&m);
  char A[n][m];
  int ans[n][m]={};
  for(int i=0;i<n;i++){
    for (int  j = 0; j < m; j++)
    {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int  j = 0; j < m; j++){
      if(A[i][j]=='#'){
        if(i!=0) {
          ans[i-1][j]+=1;
        }
        if(j!=0){
          ans[i][j-1]+=1;
        }
        if(i!=n-1){
          ans[i+1][j]+=1;
        }
        if(j!=m-1){
          ans[i][j+1]+=1;
        }
        
        if(i!=0 && j!=0){
          ans[i-1][j-1]+=1;
        }
        if(i!=0 && j!=m-1){
          ans[i-1][j+1]+=1;
        }
        if(i!=n-1 && j!=0){
          ans[i+1][j-1]+=1;
        }
        if(i!=n-1 && j!=m-1){
          ans[i+1][j+1]+=1;
        }
      }
    }
  }


  for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
       if(A[i][j]=='#'){
         printf("#");
       }else{
        char c='0'+ans[i][j];
        printf("%c",c);
      }
     }
    printf("\n");
  }
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}