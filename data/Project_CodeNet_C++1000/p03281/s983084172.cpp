#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i,j,sum1=0,sum2=0;
  cin >> n;
  for(i=1; i<=n; i++){
    if(i%2 == 1){
    	for(j=1;j<=i;j++){
          if(i%j==0)sum1++;
        }
        if(sum1 == 8)sum2++;
        sum1 = 0;
    }
  }
  cout << sum2 << endl;
}
