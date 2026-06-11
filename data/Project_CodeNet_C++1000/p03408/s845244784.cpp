#include <bits/stdc++.h>
using namespace std;

int main() {
  int B, R;
  cin >> B;
  map<string,int>data;
  for(int i=0;i<B;i++){
    string s;
    cin >> s;
    if(data.count(s)) data.at(s)++;
    else data[s]=1;
  }
  cin >> R;
  for(int i=0;i<R;i++){
    string s;
    cin >> s;
    if(data.count(s)) data.at(s)--;
    else data[s]=-1;
  }
  int count=0;
  int a=data.size();
  for(auto p:data){
    auto value=p.second;
    count=max(value,count);
  }
  cout << count << endl;
}
