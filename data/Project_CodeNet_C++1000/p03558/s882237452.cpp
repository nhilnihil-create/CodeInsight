#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
/*
方針
*/
int K;
const long long INF = 1e18;
long long dist[100010];
void bfs(){
  deque<int> q;
  q.push_back(1);
  while(!q.empty()){
    int current = q.front();
    q.pop_front();

    if(dist[current] < dist[current * 10 % K]) {
      dist[current * 10 % K] = min(dist[current],dist[current * 10 % K] );
      q.push_front(current * 10 % K);
    }


    if(dist[current + 1 % K] > dist[current] + 1){
      dist[current + 1 % K] = dist[current] + 1;
      if(current + 1 % K != 0) q.push_back(current + 1 % K);
    }
    //cout <<"current :"<< current << endl;
    //for(int i = 0; i <= K; i++) cout << dist[i%K] << " ";
    //cout << endl;

  }
}
int main(){

  cin >> K;
  for(int i = 0; i <= K; i++) dist[i] = INF;
  dist[1] = 1;
  bfs();
  //for(int i = 0; i <= K; i++) cout << dist[i%K] << " ";
  //cout << endl;
  cout << dist[0] << endl;

  return 0;
}
