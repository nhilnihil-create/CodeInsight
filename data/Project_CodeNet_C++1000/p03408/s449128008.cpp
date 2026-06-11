#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<string> s(N);
  for(int i = 0; i < N; i++){cin >> s.at(i);}
  int M;
  cin >> M;
  vector<string> t(M);
  for(int i = 0; i < M; i++){cin >> t.at(i);}

  vector<int> X(N + M);
  int v = 0; // v個目の文字列について
  string u;// 文字列uの存在する数を考える
  for(int i = 0; i < N; i++)
  {
    u = s.at(i);
    for(int j = 0; j < N; j++)
    {
      if(s.at(j) == u){X.at(v)++;}
    }
    for(int j = 0; j < M; j++)
    {
      if(t.at(j) == u){X.at(v)--;}
    }
    v++;
  }
  sort(X.rbegin(), X.rend());
  if(X.at(0) < 0){cout << '0' << endl;}
  else{cout << X.at(0) << endl;}
}