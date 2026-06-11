#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for(int i=0; i<N; i++){
    cin >> arr.at(i);
  }
  int check = 0,count = 0;
  while(1){
    for(int i=0; i<N; i++){
      if(arr.at(i)%2 == 1){
        check = 1;
        break;
        }
      arr.at(i) = arr.at(i)/2;
    }
    if(check == 1){
      break;
    }
    count++;
  }

  cout << count << endl;
}