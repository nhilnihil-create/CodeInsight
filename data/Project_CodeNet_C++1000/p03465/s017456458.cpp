#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,A[5000001],s,x;
bitset<10000001>bit;

int main(){
  
  cin>>n;
  bit.set(0);
  for(int i=1;i<=n;i++){
  	cin>>x;
    //cout<< (bit<<x) <<endl; 
    bit |= (bit<<x);
  	s += x;
  }
  
  for(int i=(s+1)/2;;i++){
  	if(bit[i]){
    	cout<<i<<endl;
      	return 0;
    }
  }
  
}