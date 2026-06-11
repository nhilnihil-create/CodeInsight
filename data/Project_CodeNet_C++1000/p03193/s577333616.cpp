#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,H,W;
  cin>>N>>H>>W;
  int count=0;
  for(int i=0;i<N;i++){
    int A=0;
    int B=0;
    cin>>A>>B;
    if(A>=H && B>=W){
      count++;
    }
  }
  cout<<count<<endl;
}