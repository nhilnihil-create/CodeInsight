#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

string S;
int N, K;

int main(){
  cin >> N >> K >> S;

  char k = S.at(K-1);

  if(k == 'A'){
    S.at(K-1) = 'a';
  }else if(k == 'B'){
    S.at(K-1) = 'b';
  }else if(k == 'C'){
    S.at(K-1) = 'c';
  }

  cout << S << endl;
}
