#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long double Y=0;
  for(int i=0;i<N;i++){
    long double x;
    string u;
    cin>>x>>u;
    if(u=="JPY")
      Y+=x;
    else
      Y+=x*380000;
  }
  cout<<Y<<endl;
}