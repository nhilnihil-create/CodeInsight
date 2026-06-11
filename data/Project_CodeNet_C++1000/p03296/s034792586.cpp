#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a;
  cin >> a;
  int tmp = a;
  int count=1;
  int ans=0;
  for(int i=1; i<N; i++){
    cin >> a;
    if(tmp==a) count++;
    else{
      ans += count/2;
      count=1;
      tmp = a;
    }
  }
  ans+=count/2;
  cout << ans << endl;
  return 0;
}