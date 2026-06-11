#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x;
  cin >> N >> x;
  vector<int>data(N);
  for(int i=0;i<N;i++){
    cin >> data.at(i);
  }
  sort(data.begin(),data.end());
  int count=0;
  for(int i=0;i<N-1;i++){
    if(x>=data.at(i)){
      count++;
      x-=data.at(i);
    }
  }
  if(x==data.at(N-1)) count++;
  cout << count << endl;
}
