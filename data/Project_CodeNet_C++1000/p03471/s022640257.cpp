#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0, Y=0;
  int a=-1,b=-1,c=-1;
  int i,j,k;
  cin >> N >> Y;
  for(i=0;i<=N;i++){
    for(j=0;j<=(N-i);j++){
      for(k=0;k<=(N-(i+j));k++){
        if(i*10000+j*5000+k*1000 == Y && i+j+k == N){
          a=i;
          b=j;
          c=k;
          break;
        }
      }
    }
  }
    cout << a << " " << b << " " << c << endl;
}