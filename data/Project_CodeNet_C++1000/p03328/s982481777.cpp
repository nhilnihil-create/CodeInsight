#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  
  int i=b-a-1;
  int H=(i*(i+1))/2;
  
  cout<<H-a<<endl;
}