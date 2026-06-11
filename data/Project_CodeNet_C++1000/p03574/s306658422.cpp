#include<bits/stdc++.h>
using namespace std;

int n,k,i,j;
char a[1000][1000],sum;

int main(){
	cin>>n>>k;
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			if(a[i][j]=='.'){
				sum='0';
				if(a[i][j+1]=='#'){
				sum++;
				}
				if(a[i+1][j+1]=='#'){
				sum++;
				}
				if(a[i][j-1]=='#'){
				sum++;
				}
				if(a[i-1][j-1]=='#'){
				sum++;
				}
				if(a[i-1][j]=='#'){
				sum++;
				}
				if(a[i+1][j-1]=='#'){
				sum++;
				}
				if(a[i-1][j+1]=='#'){
				sum++;
				}
				if(a[i+1][j]=='#'){
				sum++;
				}
				a[i][j]=sum;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			cout<<a[i][j];
		}
        cout<<endl;
	}
}
