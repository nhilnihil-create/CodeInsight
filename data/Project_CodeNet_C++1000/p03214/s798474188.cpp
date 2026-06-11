#include <bits/stdc++.h>
using namespace std;
int main () {
  int N; 
  cin>>N; int sum=0; vector<int> vec(N);
  for(int i=0;i<N;i++){
    int n;
    cin>>n; vec.at(i)=n;
    sum+=n;
  }
   
  vector<int> vec2(N);
  for(int i=0;i<N;i++) 
   if(N*vec.at(i)>=sum) vec2.at(i)=N*vec.at(i)-sum;
    else vec2.at(i)=sum-N*vec.at(i);
  int x=vec2.at(0); int y=0;
  for(int i=0;i<N;i++)
    if(vec2.at(i)<x) {x=vec2.at(i); y=i;}
  cout<<y<<endl;
}