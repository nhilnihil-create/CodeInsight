#include<bits/stdc++.h>
using namespace std;
using ll=long long;
  

int main(){
  int N;
  cin >> N;
  vector<ll> vec(N);
  int ans=0;
  for(int i=0;i<N;i++){
    cin >> vec[i];
    while(vec[i]%2==0){
      vec[i]/=2;
      ans++;
    }
  }
  cout << ans <<endl;
}

  
  