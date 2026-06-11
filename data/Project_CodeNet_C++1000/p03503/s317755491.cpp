#include<bits/stdc++.h>
using namespace std;

int f[101][11],p[101][11];

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;++i){
    for(int j=0;j<10;++j){
      cin >> f[i][j];
    }
  }
  for(int i=0;i<n;++i){
    for(int j=0;j<11;++j){
      cin >> p[i][j];
    }
  }
  int ans=-1001001001;
  for(int bit=1;bit<1<<10;++bit){
    int cal=0;
    for(int i=0;i<n;++i){
      int c=0;
      for(int j=0;j<10;++j){
        if(bit & (1<<j)){
          if(f[i][j])c++;
        }
      }
      cal+=p[i][c];
    }
    ans=max(ans,cal);
  }
  cout << ans << endl;
  return 0;
}
