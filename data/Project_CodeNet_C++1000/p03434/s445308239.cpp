#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> C(N);
  int A,B;
  int z,count;
  
  for(int i = 0; i < N; i++){
    cin >> C.at(i);
  }
  
  for(int i = 0; i < N; i++){
    z = 0;
    count = 0;
    for(int j = 0; j < N; j++){
      if(z < C.at(j)){
        z = C.at(j);
        count = j;
      }
    }
     A = A + z;
     C.at(count) = 0;
    count = 0;
     z = 0;
    for(int k = 0; k < N; k++){
     if(z < C.at(k)){
       z = C.at(k);
       count = k;
      }
    }
     B = B + z;
     C.at(count) = 0;
    }

   cout << A - B << endl;
  
}