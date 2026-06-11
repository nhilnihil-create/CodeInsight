#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N+2); A.at(0)=0; A.at(N+1)=0;
  for(int i=1;i<=N;i++){cin >> A.at(i);}
  
  vector<int> B(N+1);
  for(int i=0;i<=N;i++){B.at(i)=abs(A.at(i+1)-A.at(i));}
  
  int ansb=0;
  for(int i=0;i<=N;i++){ansb += B.at(i);}
  
  for(int i=0;i<N;i++){
    cout << ansb - B.at(i) - B.at(i+1) + abs(A.at(i+2)-A.at(i)) << endl;
  }
  
    
}