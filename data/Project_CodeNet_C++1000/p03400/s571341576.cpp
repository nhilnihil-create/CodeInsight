#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  int D; int X; cin>>D>>X;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin>>A.at(i);
  }
  for(int i=0; i<N; i++){
   if(D%A.at(i)==0)
     X+=D/A.at(i);
    else X+=D/A.at(i)+1;
  }
  cout<<X<<endl;
}