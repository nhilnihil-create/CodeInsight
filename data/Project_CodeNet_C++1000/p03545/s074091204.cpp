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
  
  int A;
  cin >> A;
  int a = A / 1000;
  A %= 1000;
  const int n = 3;
  vi vec(n);
  int b = 100;
  for (int i=0; i<n; i++){
    vec.at(i) = A / b;
    A %= b;
    b /= 10;
  }

  bitset<n> s2;
  for (int tmp=0; tmp<(1<<n); tmp++){
    bitset<n> s(tmp);

    int sum = a;
    for (int i=0; i<n; i++){
      if (s.test(i)){
        sum += vec.at(i);
      }
      else {
        sum -= vec.at(i);
      }
    }

    if (sum == 7){
      s2 = s;
      break;
    }
  }

  cout << a;
  for (int i=0; i<n; i++){
    if (s2.test(i)){
      cout << "+";
    }
    else {
      cout << "-";
    }
    cout << vec.at(i);
  }
  cout << "=7" << endl;
}
