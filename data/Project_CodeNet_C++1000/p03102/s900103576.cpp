#include<iostream>

int main(){
int n,m,c;
  std::cin >> n >> m >> c;
  int b[m];
  int a[n][m];
  for(int i=0;i<m;i++){
    std::cin >> b[i];
  }
  int t=0;
  for(int i=0;i<n;i++){
    int res=0;
    for(int j=0;j<m;j++){
         std::cin >> a[i][j];
         res+=(a[i][j]*b[j]);
   }
    if(res+c>0) t++;
 }
 std::cout << t << std::endl;
 return 0;
}
