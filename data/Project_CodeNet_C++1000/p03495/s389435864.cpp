#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  map<int,int>data;
  vector<pair<int,int>>data2;
  for(int i=0;i<N;i++){
    int s;
    cin >> s;
    if(data.count(s)) data.at(s)++;
    else data[s]=1;
  }
  for(auto p:data){
    data2.push_back(make_pair(p.second,p.first));
  }
  int a = data2.size();
  sort(data2.begin(),data2.end());
  int count=0;
  int i=0;
  while(a>K){
    count += data2.at(i).first;
    a--;
    i++;
  }
  cout << count << endl;
}
