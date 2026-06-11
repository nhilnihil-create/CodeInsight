#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> Num(N,0);
  int flag=0;
  if(S[0]=='A'){
    flag=1;
  }
  for(int i=1;i<N;i++){
    if(S[i]=='A'){
      flag=1;
      Num[i]=Num[i-1];
    }
    else if(S[i]=='C' && flag==1){
      Num[i]=Num[i-1]+1;
      flag=0;
    }
    else{
      flag=0;
      Num[i]=Num[i-1];
    }
  }
  cout << endl;
  for(int i=0;i<Q;i++){
    int l,m;
    cin >> l >>m;
    cout << Num[m-1]-Num[l-1] << endl;
  }
}