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
  int N,M;
  cin >> N >> M;
  vector<vector<bool>> like(N,vector<bool>(M,false));
  int K,A;
  for(int i=0;i<N;i++){
    cin >> K;
    for(int j=0;j<K;j++){
      cin >> A;
      --A;
      like.at(i).at(A)=true;
    }
  }

  int ans=0;
  for(int j=0;j<M;j++){
    bool flag_dislike=false;
    for(int i=0;i<N;i++){
      if(like.at(i).at(j)==false){
	flag_dislike=true;
	break;
      }
    }
    if(flag_dislike==false) ++ans;
  }

  cout << ans << endl;

  return 0;
}
