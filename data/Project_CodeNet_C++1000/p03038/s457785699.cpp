#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

typedef pair<long long, long long> P;

int main(){
  int N,M;
  cin >> N >> M;
  vector<long long> Kard(N);
  long long answer = 0;
  //cout << "GUIY" << endl;
  for(int i = 0;i < N;i++){
    cin >> Kard.at(i);
    answer += Kard.at(i);
  }
  sort(Kard.begin(),Kard.end());

  vector<P> data(M);
  //cout << "GUIsY" << endl;
  for(int i = 0;i < M;i++){
    cin >> data.at(i).second >> data.at(i).first;
  }
  sort(data.begin(),data.end(),greater<P>());

  /*for(int i = 0;i < M;i++){
    cout << data.at(i).first <<" " << data.at(i).second << endl;
  }*/

  int now = 0,sum = 0;
  for(int i = 0;i < N;i++){
    //cout << i << now << sum << endl;
    if(now < M){
    if(data.at(now).first > Kard.at(i)){
      answer += (data.at(now).first - Kard.at(i));
      sum++;
    }
    if(sum == data.at(now).second){
      sum = 0;
      now++;
    }
  }
}
  cout << answer << endl;
}

/*int main(){
  int N,M;
  cin >> N >> M;
  long long answer = 0;
  vector<long long> Kard(N);
  for(int i = 0;i < N;i++){
    cin >> Kard.at(i);
    answer += Kard.at(i);
  }
  sort(Kard.begin(),Kard.end());

  priority_queue<int> data;
  int b,c;
  for(int i = 0;i < M;i++){
    cin >> b >> c;
    for(int j = 0;j < b;j++){
      data.push(c);
    }
  }
  if(data.size() < N){
    int x = N - data.size();
    for(int i = 0;i < x;i++){
      data.push(0);
    }
  }
  for(int i = 0;i < N;i++){
    if(Kard.at(i) < data.top()){
      answer += (data.top() - Kard.at(i));
    }
    data.pop();
  }
  cout << answer << endl;
  return 0;
}*/

/*int main(){
  int N,M;
  cin >> N >> M;
  vector<long long> Kard(N);
  for(int i = 0;i < N;i++){
    Kard.at(i) = 0;
  }
  for(int i = 0;i < N;i++){
    cin >> Kard.at(i);
  }
  sort(Kard.begin(),Kard.end());
  int b,c;
  for(int i = 0;i < M;i++){
    cin >> b >> c;
    for(int j = 0;j < b;j++){
      if(Kard.at(j) < c){
        Kard.at(j) = c;
      }else{
        break;
      }
    }
    sort(Kard.begin(),Kard.end());
  }
  long long count = 0;
  for(int i = 0;i < N;i++){
    count += Kard.at(i);
  }
  cout << count << endl;
}*/
