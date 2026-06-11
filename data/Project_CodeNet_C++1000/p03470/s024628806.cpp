#include <bits/stdc++.h>
using namespace std;

int N,sum, tmp;
vector<int> d = {};


int main(){
  
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> tmp;
    d.push_back(tmp);
  }

  sort(d.begin(),d.end());

  sum=1;
  for(int i=1;i<N;i++)
    if(d.at(i) != d.at(i-1))
      sum++;

  cout << sum << endl;

  return 0;
}
