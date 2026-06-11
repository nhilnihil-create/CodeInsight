#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <bitset>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(void){
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n,k;
  cin>>n>>k;
  std::bitset<32> k_bit(k);
  int64_t result=0;

  std::vector<std::bitset<32>> a(n);
  std::vector<int64_t> b(n);
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    std::bitset<32> tmp(x);
    a[i]=tmp;
    b[i]=y;
  }

  // init result

  for(int j=0;j<n;j++){
    const std::bitset<32>& tgt=a[j];
    const int64_t& value=b[j];

    bool can_use=true;
    for(int l=31;l>=0;l--){
      if(!k_bit[l]&&tgt[l]){
        can_use=false;
        break;
      }
    }
    if(can_use){
      result+=value;
    }
  }


  for(int i=1;std::pow(2,i)<=k;i++){
    if(!k_bit[i]) continue;
    int64_t tmp_result=0;

    for(int j=0;j<n;j++){
      const std::bitset<32>& tgt=a[j];
      const int64_t& value=b[j];

      if(tgt[i]) continue;
      bool can_use=true;
      for(int l=31;l>=i+1;l--){
        if(!k_bit[l]&&tgt[l]){
          can_use=false;
          break;
        }
      }
      if(can_use){
        tmp_result+=value;
      }
    }


    result=std::max(result,tmp_result);
  }
  cout<<result<<endl;
  
  return 0;
}
