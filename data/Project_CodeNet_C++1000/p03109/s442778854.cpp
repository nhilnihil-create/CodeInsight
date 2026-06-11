#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	int y,m,d;
	scanf("%d/%d/%d",&y,&m,&d);
	//cout << y << "/" << m << "/" << d <<endl;
	if(y<2019) cout << "Heisei" << endl;
	else if(y==2019&&m<4) cout << "Heisei" << endl;
	else if(y==2019&&m==4&&d<=30) cout << "Heisei" << endl;
	else cout << "TBD" << endl;
}