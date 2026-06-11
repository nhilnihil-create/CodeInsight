#include <bits/stdc++.h>
using namespace std;

int cnt=0;
string N;
int main(){
  
  cin>>N;
  if(((N[0]==N[1])&&(N[2]==N[1]))|((N[1]==N[2])&&(N[2]==N[3])))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}