#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int k=0,l=0;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    if(k<j){
      l+=k;
      k=j;
    }else
      l+=j;
  }
  if(l>k)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}