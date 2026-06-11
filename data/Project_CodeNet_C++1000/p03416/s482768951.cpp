#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  int ans = 0;
  int A5,A4,A2,A1;
  for(int i=A; i<B+1;i++){
    A5 = i/10000;
    A4 = (i/1000)%10;
    A1 = i%10;
    A2 = (i/10)%10;
    if(A5==A1 && A4==A2)ans++;
  }
  
  cout << ans << endl;
}