#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map <int, int> a;
  for(int i = 0; i < n; i++){
    int number;
    cin >> number;
    if(a.count(number)){
      a.at(number) = a.at(number) + 1;
    }else{
      a[number] = 0;
    }
  }

  

  cout << a.size() << endl;
}
