#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;


int main(){
  int A,B;cin >> A >> B;
  char table[110][110];
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      if(i < 50){
        table[i][j] = '#';
      }else{
        table[i][j] = '.';
      }
    }
  }
  int cntW = 1,cntB = 1;
  for(int i = 0;i < 50;i += 2){
    for(int j = 0;j < 100;j++){
      if(cntW < A){
        if((i+j) % 2 == 0){
          table[i][j] = '.';
          cntW++;
        }
      }
    }
  }
  for(int i = 99;i >= 50;i -= 2){
    for(int j = 0;j < 100;j++){
      if(cntB < B){
        if((i+j) % 2 == 1){
          table[i][j] = '#';
          cntB++;
        }
      }
    }
  }
  cout << 100 << ' ' << 100 << endl;
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      cout << table[i][j];
    }
    cout << endl;
  }
}
