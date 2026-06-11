#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ,alice=0,bob=0;
  cin >> N;
  
  vector<int> vec ( N) ;
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  } 
    sort(vec.begin(), vec.end()); 
    reverse(vec.begin(), vec.end()); 
 
    for (int i = 0; i < N; i++) {

       if (i%2 ==0){
       alice = alice + vec.at(i);
       }else{
        bob = bob + vec.at(i);
          }   
    }
  cout << alice - bob << endl;
  
}
