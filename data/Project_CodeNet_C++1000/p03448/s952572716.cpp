#include <bits/stdc++.h>
using namespace std;
main(){
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  int sum=0;
  int cnt=0;
  for(int i=0;i<=A;i++){
    for(int j=0;j<=B;j++){
      for(int k=0;k<=C;k++){
        sum=0;
        sum = 500*i + 100*j + 50*k;
        if(sum==X){
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}