#include <bits/stdc++.h>
using namespace std;


int main() {
long N,K;
cin>>N>>K;
if(K%2==1){
  cout<<long(pow(N/K,3))<<endl;
}
else{
  long h=N/(K/2);
  long m=N/K;
  h-=m;
  cout<<long(pow(h,3)+pow(m,3))<<endl;
}

}
