#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> D(N);
  for(int i=0;i<N;i++){
    cin>>D[i];
  }
  
  set<int> S;
  for(int i=0;i<N;i++){
    S.insert(D[i]);
  }
  
  cout<<S.size()<<endl;
}