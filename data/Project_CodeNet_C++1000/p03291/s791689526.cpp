#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007
using namespace std;

ll work[100010][4];


int main(void){
	string s;
	cin>>s;
	rep(i,s.length()+10){
		rep(j,4){
			work[i][j]=0;
		}
	}
	work[0][0]=1;
	for(int i=1;i<=s.length();i++){
		if(s[i-1] == 'A'){
			work[i][0]=work[i-1][0];
			work[i][1]=work[i-1][1]+work[i-1][0];
			work[i][2]=work[i-1][2];
			work[i][3]=work[i-1][3];
			rep(j,4)work[i][j]%=MAX;
		}
		else if(s[i-1] == 'B'){
			work[i][0]=work[i-1][0];
			work[i][1]=work[i-1][1];
			work[i][2]=work[i-1][2]+work[i-1][1];
			work[i][3]=work[i-1][3];
			rep(j,4)work[i][j]%=MAX;
		}
		else if(s[i-1] == 'C'){
			work[i][0]=work[i-1][0];
			work[i][1]=work[i-1][1];
			work[i][2]=work[i-1][2];
			work[i][3]=work[i-1][3]+work[i-1][2];
			rep(j,4)work[i][j]%=MAX;
		}
		else{
			work[i][0]=work[i-1][0]*3;
			work[i][1]=work[i-1][1]*3+work[i-1][0];
			work[i][2]=work[i-1][2]*3+work[i-1][1];
			work[i][3]=work[i-1][3]*3+work[i-1][2];
			rep(j,4)work[i][j]%=MAX;
		}
		//cout<<work[i][0]<<" "<<work[i][1]<<" "<<work[i][2]<<" "<<work[i][3]<<endl;
	}
	cout<<work[s.length()][3]<<endl;
	return 0;
}
