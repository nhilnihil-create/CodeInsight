#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> C(N);
  int A = 0;
  int B = 0;
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
    
    C.at(count) = 0;
    if(i % 2 == 0){
     A = A + z;
    }else{
     B = B + z;
    }

    }

   cout << A - B << endl;
  
}
