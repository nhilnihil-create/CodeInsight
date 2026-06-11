#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int,int>>odd(100005);
  vector<pair<int,int>>even(100005);
  int N;
  cin >> N;
  for(int i=0;i<N/2;i++){
    int x,y;
    cin >> x >> y;
    odd.at(x).first++;
    odd.at(x).second=x;
    even.at(y).first++;
    even.at(y).second=y;
  }
  sort(odd.begin(),odd.end());
  reverse(odd.begin(),odd.end());
  sort(even.begin(),even.end());
  reverse(even.begin(),even.end());
  if(odd.at(0).second==even.at(0).second){
    if(odd.at(1).first+even.at(0).first>even.at(1).first+odd.at(0).first) cout << N-odd.at(1).first-even.at(0).first;
    else cout << N-even.at(1).first-odd.at(0).first;
  }
  else cout << N-odd.at(0).first-even.at(0).first;
}