#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B,C,D;
	cin>>A>>B>>C>>D;
  
  int hidari =A+B;
  int migi =C+D;
  
  if(hidari<migi){
  cout<<"Right"<<endl;
  }
  
  else if(hidari==migi){
  cout<<"Balanced"<<endl;
  }
  
  else{
  cout<<"Left"<<endl;
  }
  
  
}