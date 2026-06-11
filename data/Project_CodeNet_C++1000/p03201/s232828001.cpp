#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  map<int,int> mp;
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
    if(mp.count(vec.at(i))){
      mp[vec.at(i)]++;
    }
    else{
      mp[vec.at(i)] = 1;
    }
  }
  sort(vec.rbegin(),vec.rend());
  vector<int64_t> pow2(32);
  for(int i=0; i<32; i++){
    pow2.at(i) = pow(2,i);
  }
  vector<int> need(N);
  for(int i=0; i<N; i++){
    for(int j=0; j<32; j++){
      if(pow2.at(j) > vec.at(i)){
        need.at(i) = pow2.at(j) - vec.at(i);
        break;
      }
    }
  }
  
  int ans = 0;
  map<int,int> already;
  for(int i=0; i<N; i++){
    if(already.count(vec.at(i))){
      if(already[vec.at(i)] > 0){
        already[vec.at(i)]--;
        continue;
      }
    }
    if(mp.count(need.at(i))){
      if((need.at(i) != vec.at(i) && mp[need.at(i)] > 0) || (need.at(i) == vec.at(i) && mp[need.at(i)] > 1)){
        mp[need.at(i)]--;
        mp[vec.at(i)]--;
        ans++;
        if(already.count(need.at(i))){
          already[need.at(i)]++;
        }
        else{
          already[need.at(i)] = 1;
        }
      }
    }
  }
  cout << ans << endl;
}