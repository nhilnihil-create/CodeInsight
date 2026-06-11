#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007


signed main(){

	lli n;
	cin>>n;

	string s;

	char data[1000][1000]={0};

	REP(i,0,n){
		cin>>s;
		REP(j,0,n){
			data[i][j] = s.at(j);
			data[i][j+n] = s.at(j);
			data[i+n][j] = s.at(j);
			data[i+n][j+n] = s.at(j);
		}
	}

	lli cnt=0;
	for(lli a=0;a<n;a++){
		lli b=0;
		if(DEBUG)cout<<"a="<<a<<" b="<<b<<endl;
		/*judge*/
		lli flag=0;
		for(lli y=0;y<n;y++){
			for(lli x=0;x<n;x++){
				lli nextI = y+b;
				lli nextJ = x+a;
				lli targetI = x+b;
				lli targetJ = y+a;
				if(DEBUG){
					cout<<"nextI="<<nextI<<" nextJ="<<nextJ<<endl;
					cout<<"data[i][j]="<<data[nextI][nextJ]<<" data[j][i]="<<data[targetI][targetJ]<<endl;
				}
				if(data[nextI][nextJ]!=data[targetI][targetJ]){
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
		if(flag==0)cnt+=n;
	}
	
	cout<<cnt<<endl;

	return 0;
}