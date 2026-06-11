#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N;
	cin >> N;
  
  string S;
  cin >> S;
  vector<int> c(N);
  for(int i=1; i<N; i++){
    if(S.at(i)=='E') c.at(0)++;
    }
  int leader = 0;
  for(int i=1; i<N; i++){
  	c.at(i) = c.at(i-1);
    if(S.at(i-1)=='W') c.at(i)++;
    if(S.at(i)=='E') c.at(i)--;
    if(c.at(i) < c.at(leader)) leader = i;
  }
  cout << c.at(leader) << endl;
  return 0;
} 
    
    