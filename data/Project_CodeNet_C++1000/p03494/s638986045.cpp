#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,cnt=0;
  int num[N];
  int flag=0;
  
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> num[i];
  }
  while(flag==0){
    for (int i=0; i<N; i++){
      if (num[i]%2!=0){
        flag=1;
        break;
      }else{
        num[i]/=2;
      }
    }
    if(flag==0) cnt++;
  }
  cout << cnt << endl;
}
