#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=1e5;

int s[N],t[N],c[N];
int sm[N*2];
int tt[N*2];


int main(){
	int n,C;
	cin>>n>>C;
	
	for(int i=0;i<n;i++){
		cin>>s[i]>>t[i]>>c[i];
	}
	
	for(int i=1;i<=C;i++){
		memset(tt,0,sizeof(tt));
		
		for(int j=0;j<n;j++){
			if(c[j]==i)
				tt[2*s[j]-1]++,
				tt[2*t[j]]--;
		}
		
		for(int j=0;j<2*N;j++)
			tt[j]+=tt[j-1];

		for(int j=0;j<2*N;j++)
			if(tt[j]>0)
				sm[j]++;
	}
	
	cout<<*(max_element(sm,sm+2*N))<<endl; 
}
