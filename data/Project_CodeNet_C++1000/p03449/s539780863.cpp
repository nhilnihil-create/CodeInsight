#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<vector<int>> a(2,vector<int>(N));
  vector<vector<int>> sum(2,vector<int>(N,0));
  
  for(int i=0;i<2;++i){
    for(int j=0;j<N;++j){
      cin >> a.at(i).at(j);
      if(j!=0)
	sum.at(i).at(j)=sum.at(i).at(j-1)+a.at(i).at(j);
      else sum.at(i).at(j)=a.at(i).at(j); 
    }
  }

  int ans=0;
  int temp;
  for(int i=0;i<N;++i){
    temp=sum.at(0).at(i)+sum.at(1).at(N-1)-sum.at(1).at(i)+a.at(1).at(i);
    ans=max(ans,temp);
  }

  cout << ans << endl;

  return 0;
}
