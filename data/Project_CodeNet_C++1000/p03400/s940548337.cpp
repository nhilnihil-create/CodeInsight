#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,D,X;
  cin>>N>>D>>X;
  D--;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    X+=D/j+1;
  }
  cout<<X<<endl;
}