#include <iostream>
#include <vector>
using namespace std;

uint getResult(const vector<pair<uint, uint>> &scales,
               const uint height, const uint width){
  uint result = 0;
  for(pair<uint, uint> scale : scales){
    if(scale.first >= height && scale.second >= width){
      result++;
    }
  }
  return result;
}

int main(){
  uint N, H, W;
  cin >> N >> H >> W;
  
  vector<pair<uint, uint>> AB(N);
  for(uint i = 0; i < N; i++){
    cin >> AB[i].first >> AB[i].second;
  }

  uint result = getResult(AB, H, W);
  cout << result;
  return 0;
}