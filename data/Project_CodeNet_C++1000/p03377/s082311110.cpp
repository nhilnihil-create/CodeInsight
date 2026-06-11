#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int main(){
  int A,B,X;
  cin>>A>>B>>X;
  if(A<=X&&X<=A+B){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
