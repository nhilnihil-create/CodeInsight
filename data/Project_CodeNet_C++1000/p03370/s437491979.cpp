#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,X;
  cin >> N >> X;
  
  vector<int> m(N);
  for(int i = 0; i < N; i++){
    cin >> m.at(i);
  }
  
  int kindsum = 0;
  for(int i = 0; i < N; i++){
    kindsum += m.at(i);
  }
  X -= kindsum;
  
  sort(m.begin(),m.end());
  int count = X / m.at(0);
  
  cout << count + m.size() << endl;
}