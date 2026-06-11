#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
 
  cin >> N;
  vector<string> S(N);
  vector<int> Snum(N,0);
  vector<int> Num(N,0);
  
  for (int i = 0; i < N; i++)
    cin >> S.at(i);
  
  cin >> M;
  vector<string> T(M);
  vector<int> Tnum(M,0);
  
  for (int i = 0; i < M; i++)
    cin >> T.at(i);
  
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if(S.at(i)==S.at(j))
        Snum.at(i) += 1; 
  
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      if(T.at(i)==T.at(j))
        Tnum.at(i) += 1; 
  
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++){
      if(S.at(i) == T.at(j)){
        Num.at(i) = Snum.at(i) - Tnum.at(j);
  		break;
      }else{
        Num.at(i) = Snum.at(i);
      }
    }
  
  int max = 0;
  for (int i = 0; i < N; i++)
	if(Num.at(i) > max)
      max = Num.at(i);
   
  cout << max << endl;
}