#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
    }
  long long sum=1;
  for(int i=0;i<N;i++){
      sum*=3;
  }
  long long kake=1;
  for(int i=0;i<N;i++){
      if(vec.at(i)%2==0){
          kake*=2;
      }
      else{
          kake*=1;
      }
  }
  cout <<sum-kake<<endl;

}