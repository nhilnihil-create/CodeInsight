#include<iostream>
using namespace std;

int digSum(int n){
  int sum=0;
    while(n>0){
    sum+=(n%10);
    n/=10;
    }
  return sum;
    }

int main(){
  int N, A, B;
  cin>>N>>A>>B;
  int cnt=0;
  int total=0;
  for(int i =1;i<=N;++i){
  int sum=digSum(i);
    if(sum>=A&&sum<=B){
      total+=i;
    }
  }
  cout<<total<<endl;
}
