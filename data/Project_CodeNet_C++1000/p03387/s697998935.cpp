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
  vi vec(3);
  for (int i=0; i<3; i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());

  int a = vec.at(2);
  int b = vec.at(1);
  int c = vec.at(0);

  int x = a - b;
  int y = a - (c + x);

  int z;

  if (y % 2 == 0){
    z = x + (y/2);
  }
  else {
    z = x + (y/2) + 2;
  }

  cout << z << endl;
}
