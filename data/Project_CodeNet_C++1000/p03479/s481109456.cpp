#include<bits/stdc++.h>
using namespace std;
int main(){
  long long X,Y;cin>>X>>Y;
  long long Z=Y/X;
  long long count=1;
  while(Z>=2){
    Z=Z/2;
    count++;
  }
  cout<<count<<endl;
}
