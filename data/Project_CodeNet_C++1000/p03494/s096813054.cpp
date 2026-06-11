#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int ans=100;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    int ca;
  if(x%2 ==1){
    ans=0;
     break;}
    else{
      ca=1;
      int A=x/2;
    while(A%2==0){
      A/=2;
      ca++;}
      }
    if(ans>ca) ans=ca;
    }
        cout << ans <<endl;
}
