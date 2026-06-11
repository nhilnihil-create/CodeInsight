#include <iostream>
using namespace std;
int main(){
  long long n,y;
  cin >> n >> y;
  long long i,j;
  for(i=0;i<=n;i++){
    for(j=0;j<=n-i;j++){
      if((y-1000*i-5000*j)/10000==n-i-j && (y-1000*i-5000*j)%10000==0 && (y-1000*i-5000*j)>=0){
        cout << n-i-j << " " << j << " " << i << "\n";
        return 0;
      }
    }
  }
  cout << -1 << " " <<  -1 << " " << -1 << "\n";
  return 0;
}