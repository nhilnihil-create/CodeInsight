#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  long double sum=0;
  for(int i=0;i<N;i++){
  double x;
    string v;
    cin>>x>>v;
    if(v=="JPY"){
    sum+=x;
    }
    else{
    sum+=380000 * x;
    }
  }
  cout<<sum<<endl;
}