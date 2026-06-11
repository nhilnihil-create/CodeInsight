#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  int n,m;
  scanf("%d %d",&n,&m);
  char A[n][m];
  vector<vector<int>> ans(n+2,vector<int>(m+2,0));
  for(int i=0;i<n;i++){
    for (int  j = 0; j < m; j++){
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int  j = 0; j < m; j++){
      if(A[i][j]=='#'){
        ans.at(i).at(j)+=1;
        ans.at(i).at(j+1)+=1;
        ans.at(i).at(j+2)+=1;
        ans.at(i+1).at(j)+=1;
        ans.at(i+1).at(j+1)+=1;
        ans.at(i+1).at(j+2)+=1;
        ans.at(i+2).at(j)+=1;
        ans.at(i+2).at(j+1)+=1;
        ans.at(i+2).at(j+2)+=1;
      }
    }
  }
  for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
       if(A[i][j]=='#'){
         printf("#");
       }else{
          printf("%c",'0'+ans[i+1][j+1]);
      }
    }
    printf("\n");
    
  }
}
int main(){
  solve();
  return 0;
}