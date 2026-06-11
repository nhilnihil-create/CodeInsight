#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
  int N;
  cin>>N;
  long double p[3000];
  for(int i=1;i<=N;i++) cin>>p[i];
  long double q[3000][3000]; //q[k][i] k枚中i枚が表である確率
  q[0][0]=1;
  for(int i=1;i<=N;i++){
    for(int j=0;j<=i;j++){
      if(j==0){
        q[i][j]=q[i-1][0]*(1-p[i]);
      }
      else if(j==i) q[i][j]=q[i-1][i-1]*p[i];
      else q[i][j]=q[i-1][j-1]*p[i]+q[i-1][j]*(1-p[i]);
    }
  }
  long double answer=0;
  for(int i=N/2+1;i<=N;i++) answer+=q[N][i];
  cout<<setprecision(16)<<answer<<endl;
  
return 0;
}