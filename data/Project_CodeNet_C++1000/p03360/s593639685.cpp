#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int K;
  cin>>K;
  int max_num=max(A,max(B,C));
  int remain=A+B+C-max_num;
  cout<<remain+max_num*pow(2,K)<<endl;
}