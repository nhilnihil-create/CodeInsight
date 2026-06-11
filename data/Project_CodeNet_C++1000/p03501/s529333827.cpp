#include <bits/stdc++.h>
using namespace std;
int N,A,B,price;
int main(){
  cin >> N >> A >> B;
  price = N * A;
  cout << (price < B?price:B) << endl;
}