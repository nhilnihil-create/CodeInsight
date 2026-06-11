#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,D,X;
  cin>>N;
  cin>>D>>X;
  vector<int> a(N);
   for(int i=0;i<N;i++)
     cin>>a.at(i);
  int count_outside=0;
  for(int i=0;i<N;i++){
    int count_inside=0,j=0;
    while(j*a.at(i)+1<=D){
      j++;
      count_inside++;
    }
    count_outside+=count_inside;
  }
  cout<<count_outside+X<<endl;
}