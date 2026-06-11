#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  int max=0;
  
  cin >> N;
  vector<string> Ns(N);
  for (int i=0; i<N; i++)
    cin >> Ns.at(i);
  
  cin >> M;
  vector<string> Ms(M);
  for (int i=0; i<M; i++)
    cin >> Ms.at(i);
  
  for (int i=0; i<N; i++){
    int num=0;
    for (int j=0; j<N; j++){
      if (Ns.at(i)==Ns.at(j)) num++;
    }
    for (int k=0; k<M; k++){
      if (Ns.at(i)==Ms.at(k)) num--;
    }
    if (num>max) max=num;
  }
  
  for (int i=0; i<M; i++){
    int num=0;
    for (int j=0; j<M; j++){
      if (Ms.at(i)==Ms.at(j)) num--;
    }
    for (int k=0; k<N; k++){
      if (Ms.at(i)==Ns.at(k)) num++;
    }
    if (num>max) max=num;
  }
  
  cout << max << endl;
}
