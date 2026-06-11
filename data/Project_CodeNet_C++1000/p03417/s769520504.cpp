#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int N, M;
  cin >> N >> M;

  if(N>M){
    swap(N, M);
  }

  if (N==1 && M==1){
    cout << 1 << endl;
  }
  else if (N==1 && M!=1){
    cout << M-2 << endl;
  }
  else {
    cout << (long long)(N-2)*(M-2) << endl;
  }

  return 0;
}
