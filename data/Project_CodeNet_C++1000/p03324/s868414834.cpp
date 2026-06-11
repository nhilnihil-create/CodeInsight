#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int D,N;
  cin>>D>>N;
  if(N==100)
    cout<<(int)pow(100,D)*101<<endl;
  else
    cout<<(int)pow(100,D)*N<<endl;
}