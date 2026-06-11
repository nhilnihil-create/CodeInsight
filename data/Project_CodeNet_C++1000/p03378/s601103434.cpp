#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x;
  cin >> n >> m >> x;
  vector<int> gate(m);
  for(int i=0; i<m;i++){
    cin >> gate.at(i);
  }
  int count_gate=0;
  for(int i=0;gate.at(i)<x;i++){
	count_gate++;
  }
  if(count_gate <= m /2){
    cout << count_gate <<endl;
    return 0;
  }
	else{cout << m - count_gate << endl;}
}