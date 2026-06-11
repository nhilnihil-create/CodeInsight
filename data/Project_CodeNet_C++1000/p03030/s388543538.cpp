#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<tuple<string,int,int>> A;
  for(int i=1;i<N+1;i++){
    string S;
    int P;
    cin >> S >> P;
    P*=-1;
    A.push_back(tie(S,P,i));
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    cout << get<2>(A.at(i)) <<endl;
  }
}
    
  