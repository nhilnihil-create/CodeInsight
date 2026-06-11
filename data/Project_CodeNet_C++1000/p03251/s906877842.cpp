#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int syc(long i,long Min,long Max){
	if(Min <= i && i <= Max){
		return 1;
	}else{
		exit(1);
		//return 0;
	}
}

int main(){
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	
	syc(n,1,100);
	syc(m,1,100);
	syc(x,-100,100);
	syc(y,-100,100);
	
	int a[n],b[m];
	int temp;
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++){
		cin >> b[i];
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(b[i]>b[j]){
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	
	if(a[n-1]<b[0] && x<b[0] && b[0]<=y){
		cout << "No War" << endl;
	}else{
		cout << "War" << endl;
	}
	
	return 0;
}
