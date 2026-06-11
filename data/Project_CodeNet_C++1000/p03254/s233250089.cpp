#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Ncandy,buf;
  cin >> N >> Ncandy;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end());

  int remain_candy= Ncandy;
  int ans= 0;
  for(auto elem:data){
    if(remain_candy >= elem){
      remain_candy-= elem;
      ans++;
    }
    else{
      remain_candy= 0;
      break;
    }
  }
  if(remain_candy > 0){ ans--; }
  
  cout << ans << endl;
}