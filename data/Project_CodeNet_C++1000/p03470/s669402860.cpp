#include <bits/stdc++.h>
using namespace std;

int main(void){

  int N,ans = 1;
  cin >> N;
  int data[N];
  for(int i=0;i<N;i++) cin >> data[i];
  sort(data,data+N,greater<int>());
  for(int i=0;i<N-1;i++){
      if(data[i] > data[i+1]) ans++;
      
  }
  cout << ans << endl;
}
