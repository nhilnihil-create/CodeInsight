#include <bits/stdc++.h>
using namespace std;


int main(){
  string N;
  cin>>N;
int sum=0;
  for(int i=0;i<(int)(N.length());i++){
    char a = N.at(i);
    int b = a - '0';
    sum+=b;
}
  int b = stoi(N);
  if(b%sum==0){
    cout<<"Yes"<<endl;
  }else{
cout<<"No"<<endl;
  }
}