#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const long long int ARRAY = 200005;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  vector<int> bucket(ARRAY);
 
  for(int i=0; i<N; i++){
    cin >> a[i];
    bucket[a[i]]++;
  } //for
 
  int num_type = 0;
  for(int i=0; i<N+1; i++){
    if(bucket[i] > 0) num_type++;
  }//for
  
  sort(bucket.rbegin(), bucket.rend());
  int i = 1;
  int ans = 0;
  while(num_type > K){
    if( bucket[N-i] > 0){
       num_type--;
       ans += bucket[N-i];
    }//if   
    i++;
  } //while

  cout << ans << "\n";
}//main
