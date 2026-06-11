#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  int count=0;
  for(int i=1;i<=n;i++){
  	if(i%2==1){
      	int a=0;
    	for(int j=1;j<=i;j++){
        	if(i%j==0) a++;
        }
      	if(a==8) count++;
    }
  }
  cout<<count<<endl;
}