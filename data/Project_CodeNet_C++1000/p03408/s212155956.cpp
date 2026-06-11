#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t.at(i);
  }

  int max = 0;
  int c = 0;
  string tmp;
  
  for (int i = 0; i < N; i++)
  {
    tmp = s.at(i);
    c = 0;
    for (int j = 0; j < N; j++)
    {
      if( s.at(j) == tmp )
        c++;
    }
    for (int j = 0; j < M; j++)
    {
      if( t.at(j) == tmp )
        c--;
    }
    if (c > max)
    {
      max = c;
    }
  }
  cout << max << endl;
}
