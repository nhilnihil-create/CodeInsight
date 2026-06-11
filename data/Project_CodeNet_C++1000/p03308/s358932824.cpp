#include <bits/stdc++.h>
using namespace std;

int max_a(vector <int>V){
  int m;
  m=V[0];
  for(int i;i<V.size();i++){
    m=max(m,V[i]);
  }
  return m;
}

int min_a(vector <int>V){
  int m;
  m=V[0];
  for(int i;i<V.size();i++){
    m=min(m,V[i]);
  }
  return m;
}



int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0;i<N;i++){
    cin >> A[i];
  }
  cout<<max_a(A)-min_a(A)<< endl;
}
