#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin>>N;
  int sum=0;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  int x=0;
  for(int i=1;i<N;i++){
    x+=vec.at(i);
  }
  if(x>vec.at(0)){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
}


 

