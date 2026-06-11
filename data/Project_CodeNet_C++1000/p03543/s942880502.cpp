#include <bits/stdc++.h>
using namespace std;

int main(){
int p;
  cin >> p;
  if((p%1000)%111==0||(p-(p%10))%1110==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}