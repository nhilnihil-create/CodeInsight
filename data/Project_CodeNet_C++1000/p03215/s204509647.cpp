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
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

typedef int64_t int64;
typedef uint64_t uint64;
typedef std::bitset<64> bitset;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n,k;
  cin>>n>>k;
  std::vector<uint64> a(n);
  for(int i = 0; i < n; ++i){
    cin>>a[i];
  }

  std::unordered_multiset<bitset> set;

  for(int l=0;l<n;l++){
    uint64 sum=0;
    for(int r=l;r<n;r++){
      sum+=a[r];
      set.insert(bitset(sum));
    }
  }

  for(int bi=62;bi>=0;bi--){
    int count=0;
    for(auto bs:set){
      if(bs[bi]) count++;
    }
    if(count>=k){
      std::unordered_multiset<bitset> new_set;
      for(auto itr=set.begin();itr!=set.end();itr++){
        if((*itr)[bi]){
          new_set.insert(*itr);
        }
      }
      set=new_set;
    }
  }

  if(set.size()==0){
    cout<<0<<endl;
  }else{
    uint64 result=UINT64_MAX;
    for(auto bs:set){
      result=result&bs.to_ulong();
    }
    cout<<result<<endl;
  }





  return 0;
}
