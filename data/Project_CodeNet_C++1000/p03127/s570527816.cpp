#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(b==0) return a;
  else gcd(b,a%b);
}



int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int num=a[0];
  for(int i=1;i<n;i++){
    num=gcd(num,a[i]);
  }
  cout<<num<<endl;
}
