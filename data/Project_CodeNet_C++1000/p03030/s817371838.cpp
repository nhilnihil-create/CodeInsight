#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int N,P;
  string S;
  cin >> N;
  vector<pair<string, pair<int, int> > >table;
  for(int i=0;i<N;i++){
    cin >> S >> P;
    P = -P;
    table.push_back(make_pair(S,make_pair(P,i)));
  }
  sort(table.begin(),table.end());
  for(int i=0;i<N;i++){
    cout << 1+table[i].second.second<< endl;
  }
}
