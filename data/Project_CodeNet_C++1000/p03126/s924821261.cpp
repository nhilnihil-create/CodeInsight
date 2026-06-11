#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  map<string,int> A;
  for(int i=0;i<N;i++){
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
      string S;
      cin >> S;
      A[S]++;
    }
  }
  int count=0;
  for(auto it=A.begin();it!=A.end();it++){
    if((*it).second==N){
      count++;
    }
  }
  cout << count << endl;
} 