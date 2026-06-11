#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> A={1,2,3,5,6,9,10,13,17};
  int N;
  cin>>N;
  for(int i:A)
    if(N==i){
      cout<<"No"<<endl;
      return 0;
    }
  cout<<"Yes"<<endl;
}