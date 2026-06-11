#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  int n,m,count;
  scanf("%d %d",&n,&m);
  vector<vector<char>> A(n,vector<char>(m));
  int x[8]={-1,-1,-1,0,0,1,1,1};
  int y[8]={-1,0,1,-1,1,-1,0,1};
  for(int i=0;i<n;i++){
    for (int  j = 0; j < m; j++){
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int  j = 0; j < m; j++){
      if(A[i][j]!='#'){
        count=0;
        for (int k = 0; k < 8; k++)
        {
          int xx=y[k]+i;
          int yy=x[k]+j;
          if(xx<0 || xx>=n) continue;
          else if(yy<0 || yy>=m) continue;
          else if(A[xx][yy]=='#')count++;
        }
        printf("%c",'0'+count);
      }else{
        printf("#");
      }
    }
    printf("\n");
  }
}
int main(){
  solve();
  return 0;
}