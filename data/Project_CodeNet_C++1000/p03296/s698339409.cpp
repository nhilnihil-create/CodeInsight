#include <bits/stdc++.h>
using namespace std;
 
int main(){
 	int N,cr,cl,ct=0;
  	cin>>N;
	cin>>cl;
  	for(int i=0;i<N-1;i++){
      	cin>>cr;
    	if(cl==cr){cl=-1*cr;ct++;}
      	else cl=cr;
  	}   
  cout<<ct<<endl;
}