#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,p;
  string s;
  scanf("%d",&N);
  vector<tuple<string,int,int>>T(N);
  for(int i =0;i < N; i++){
    cin >> s >> p;
    p *= -1;
    T[i] = make_tuple(s,p,i+1);
  }
  
  sort(T.begin(), T.end());
  
  for(int i = 0; i < N; i++){
    cout <<get<2>(T[i]) << endl;
  }
}