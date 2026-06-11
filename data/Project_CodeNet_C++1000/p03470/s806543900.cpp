#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N;
  
  vector<int> vec1 ( N) ;
  for (int i = 0; i < N; i++) {
    cin >> vec1.at(i);
  } 
  for (int j = 0; j < N; j++) {
     for (int k = (j+1); k < N; k++) {
          if (vec1.at(j)==vec1.at(k)){
            vec1.at(k) =0;
          }
          }
     }
  int count=0;
      for (int j = 0; j < N; j++) {
        if (vec1.at(j)!=0){
            count ++;
          }
  		}
  cout << count << endl;
}
