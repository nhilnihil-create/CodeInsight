#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   cin>>N;
   vector<vector<int>> a(2,vector<int>(N));
   for(int i=0;i<2;i++){
      for(int j=0;j<N;j++){
         cin>>a[i][j];
      }
   }
   int maxx=0;
   int y=0;
   for(int i=0;i<N;i++){
      int x=0;
      for(int j=0;j<N;j++){
         if(i==j){
         x+=a[0][j];
         y=1;
         }
         x+=a[y][j];
      }
         y=0;
         maxx=max(maxx,x);
   }
   cout<<maxx<<endl;
   
   return 0;
}
