#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>

int type[1000004];
int main(){
  int N;
  scanf("%d", &N);
  std::map<std::string, int > mp;
  mp["Vacant"]=0;
  mp["Male"]=1;
  mp["Female"]=-1;
  std::cout << 0 << std::endl;
  std::string s;
  std::cin >> s;
  type[0]=mp[s];
  type[N]=mp[s];
  int left = 0;
  int right = N;
  while(right-left>1){
    int mid = (right+left)/2;
    std::cout << mid << std::endl;
    std::cin >> s;
    if (s=="Vacant"){
      return 0;
    }
    type[mid]=mp[s];
    if (((mid-left)%2==1 && type[left]==-type[mid]) ||
        ((mid-left)%2==0 && type[left]== type[mid])){
      // left~midの間に空席はないので、空席候補はmid~right
      left=mid;
    } else {
      right=mid;
    }
  }
  return 0;
}
