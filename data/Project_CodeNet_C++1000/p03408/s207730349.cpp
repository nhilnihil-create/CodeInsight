#include <bits/stdc++.h>
using namespace std;

int my_max(int x, int y) {
 
  if (x > y) {
    return x;
  }else{
    return y;
  }
  }
  
int main() {
  int N, M;
  int ans=0;
  cin >> N;
  vector<string> vec_blue(N);
    for (int i=0;i<N;i++){
   cin >> vec_blue.at(i);
  }
  
  cin >> M;
  vector<string> vec_red(M);
   for (int i=0;i<M;i++){
   cin >> vec_red.at(i);
  }
  
  vector<int> vec_count(N,0);
   for(int i =0;i<N;i++){
     for (int j =0;j<N;j++){
    	 if (vec_blue.at(i) == vec_blue.at(j)){
           vec_count.at(i) += 1;
         }
 	 }
   }
   for(int i =0;i<N;i++){
     for (int j =0;j<M;j++){
    	 if (vec_blue.at(i) == vec_red.at(j)){
           vec_count.at(i) -= 1;
         }
 	 }
   }
 	for(int i= 0;i<N;i++){
      ans = my_max(vec_count.at(i),ans);
    }
         
  cout << ans << endl;
  return 0;
}