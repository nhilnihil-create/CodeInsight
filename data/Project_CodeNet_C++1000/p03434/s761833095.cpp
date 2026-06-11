#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int i,j;
  int sum_a = 0;
  int sum_b = 0;
  int max_vec;
  int vec_point;
  

  cin >> a ;
  
  vector <int>vec(a);
  vector <int>vec_big_order(a);
  for(i=0;i<a;i++){
    cin >> vec.at(i);
    }
  for(j=0;j<a;j++){
   max_vec = 0;
   vec_point = 0;
   for(i=0;i<a;i++){
    if(max_vec < vec.at(i)){
      vec_point = i;
      max_vec = vec.at(i);
      }
   }
    vec_big_order.at(j) = max_vec;
    vec.at(vec_point) = 0;
    }
  
  for(i=0;i<a;i+=2){
    sum_a = vec_big_order.at(i) + sum_a;
  }
  
    
  for(i=1;i<a;i+=2){
     sum_b = sum_b + vec_big_order.at(i);
   }
  

  cout << sum_a - sum_b <<endl;
  }
