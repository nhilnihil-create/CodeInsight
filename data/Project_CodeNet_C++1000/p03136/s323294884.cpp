#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, L;
  int maxL = 0;
  int sumL = 0;
  vector<int> length;
  cin >> N;
  
  for(int i = 0; i < N; i++){
    cin >> L;
    length.push_back(L);
    sumL += L;
  }
  
  maxL = *max_element(length.begin(), length.end());
  if(maxL < sumL - maxL){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
