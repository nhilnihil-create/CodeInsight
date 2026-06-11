#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  if(n%2==0){
    cout << n << " " << n << " " << n/2 << endl;
  }else{
    for(int i=1;i<=3500;i++){
      for(int j=1;j<=3500;j++){
        int64_t a=n*i+n*j;
        if(4*i*j>a&&(n*i*j)%(4*i*j-a)==0){
        cout << i << " " << j << " " << (n*i*j)/(4*i*j-a);
        return 0;
        }
      }
    }
  }
  return 0;
}