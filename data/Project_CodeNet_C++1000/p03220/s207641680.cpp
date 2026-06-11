#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t,A;
  cin >> n >> t >> A;
  double kion=10e5,baf;
  int ans;
  for(int i=0;i<n;i++){
    cin >> baf;
    if(kion>abs(A-t+baf*0.006)){
      kion=abs(A-t+baf*0.006);
      ans=i+1;
    }
  }
  cout << ans << endl;
  return 0;
}