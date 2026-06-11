#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,N,M;
  cin >> N;
  vector<string> Blue(N);
  for(i=0;i<N;++i)
    cin >> Blue.at(i);
  cin >> M;
  vector<string> Red(M);
  for(i=0;i<M;++i)
    cin >> Red.at(i);
  int money,lastmoney=0;
  while(N--){
    money = 0;
    for(i=N;i>=0;--i)
      money += (Blue.at(i)==Blue.at(N));
    for(i=0;i<M;++i)
      money -= (Red.at(i)==Blue.at(N));
    if(money > lastmoney)
      lastmoney = money;
  }
  cout << lastmoney << endl;
}
