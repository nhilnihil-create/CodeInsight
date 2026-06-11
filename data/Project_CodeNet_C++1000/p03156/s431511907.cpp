#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  int count_no1 = 0;
  int count_no2 = 0;
  int count_no3 = 0;
  
  for(int j=0; j<N; j++){
    if(vec.at(j) <= A){
      count_no1++;
    }
    else if(vec.at(j) <= B){
      count_no2++;
    }
    else{
      count_no3++;
    }
  }
  int ans = min(count_no1,count_no2);
  ans = min(ans, count_no3);
  cout << ans << endl;
}