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
#include <utility>

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > D;
  int DD;
  std::vector<int > time;
  time.push_back(0);
  std::map<int, int> count;
  for (int i=0; i<N; i++){
    scanf("%d", &DD);
    count[DD]++;
  }
  for (auto &entry: count){
    if (entry.second>2){
      printf("0\n");
      return 0;
    } else if (entry.second==2){
      time.push_back(entry.first);
      time.push_back(24-entry.first);
    } else if (entry.first%12==0){
      time.push_back(entry.first);
    } else {
      D.push_back(entry.first);
      //printf("pushing D to %d\n", entry.first);
    }
  }
  if (D.size()+time.size()>24){
    printf("0\n");
  } else {
    int s;
    if (D.size()>0){
      s=0;
      for (int i=0; i<(1<<D.size())-1; i++){
	//printf("i=%d\n", i);
	std::vector<int > vec(time.size());
	std::copy(time.begin(), time.end(), vec.begin());
	for (int j=0; j<D.size(); j++){
	  if ((i&(1<<j))!=0){
	    vec.push_back(D[j]);
	  } else {
	    vec.push_back(24-D[j]);
	  }
	  //printf("time[%d]=%d\n", vec.size()-1, vec[vec.size()-1]);
	}
	std::sort(vec.begin(), vec.end());
	int temp=1000000;
	for (int j=0; j<vec.size()-1; j++){
	  temp=std::min(temp, vec[j+1]-vec[j]);
	}
	temp=std::min(temp, 24-vec[vec.size()-1]);
	//printf("i=%d, temp=%d\n", i,temp);
	s=std::max(s, temp);
      }
    } else {
      std::sort(time.begin(), time.end());
      s=100000;
      for (int i=0; i<time.size()-1; i++){
	s=std::min(s, time[i+1]-time[i]);
      }
      s=std::min(s, 24-time[time.size()-1]);
    }
    std::cout << s << std::endl;
  }
  return 0;
}