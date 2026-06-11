#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ,Big=0,big=0,alice=0,bob=0,count=0;
  cin >> N;
  
  vector<int> vec1 ( N) ;
  for (int i = 0; i < N; i++) {
    cin >> vec1.at(i);
  } 
  for (int j = 0; j < N; j++) {
     for (int k = (j+1); k < N; k++) {
          if (vec1.at(j)<vec1.at(k)){
            Big=k;
            big=vec1.at(j);
            vec1.at(j)=vec1.at(k);
            vec1.at(k)=big;
          }
     }
       count ++;
       if (count%2 !=0){
       alice = alice + vec1.at(j);
       }else{
        bob = bob + vec1.at(j);
          }
         vec1.at(j) = 0;
     
  }
  cout << alice - bob << endl;
  
}
