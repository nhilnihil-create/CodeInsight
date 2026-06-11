#include <iostream>
#include <vector>
using namespace std;

void how_many_two(int &a , int &count){
  while (a % 2 == 0) {
    a /= 2;
    count ++;
  }
}

int main(){
  int n , a , count;
  cin >> n;
  for (int i = 0 ; i < n ; i ++) {
    cin >> a;
    how_many_two(a , count);
  }
  cout << count << endl;
}