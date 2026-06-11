#include <bits/stdc++.h>
using namespace std;
int main(){
  int N , a , b = 1;
   cin >> N;
  vector<int> moti(N);
  for(int i = 0 ; i < N ; i++){
    cin >> a;
    moti.at(i) = a;
  }
  sort(moti.begin() , moti.end());
  for(int i = 0 ; i < N - 1 ; i++){
    if(moti.at(i) != moti.at(i + 1)){
      b++;
    }
  }
  cout << b << endl;
}