#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N;
  
  vector<int> vec ( N) ;
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  } 
    sort(vec.begin(), vec.end()); 
 
    for (int i = 0; i < N; i++) {
      for (int ii = i+1; ii < (N); ii++) {
       if (vec.at(i)==vec.at(ii)){
         vec.at(ii)= 0;
       }  
    }
    }
  int count =0;
   for (int i = 0; i < N; i++) {
      if (vec.at(i)!=0){
       count++;
       }  
   }
  cout << count << endl;
  
}