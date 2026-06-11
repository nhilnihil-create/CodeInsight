#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;int count=1;cin>>n;
  	vector<int >df(n*100000,0);
  	df[n]=1;
  	while(df[n]!=2){
    	if(n%2==0){
          n=n>>1;
        }
      else{
      	n = 3*n+1;
      }
      df[n]+=1;
      count+=1;
    }
  	cout<<count;
}