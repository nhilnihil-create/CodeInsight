#include <bits/stdc++.h>
using namespace std;
int main(){
  double keta=0;
  int N,n=0,a,num,counter;
  cin>>N;
  num=N;
  while(num!=0){
    num/=10;
    keta++;
  }
  a=N;
  counter=keta;
  for(counter;counter>=0;counter--){
    int i=N/pow(10,keta);
    N=N-(i*pow(10,keta));
    n=n+i;
    keta--;
    //cout<<i<<" "<<n<<" "<<N<<" "<<keta<<" "<<endl;
  }
  if(a%n==0){
    cout<<"Yes"<<endl;
  }
  else
    cout<<"No"<<endl;
}