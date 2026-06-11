#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  int ans=0;
  for(int i=1;i<N;){
    if(a.at(i)==a.at(i-1)){
      ans++;
      i+=2;
    }else{
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
