#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int main(){
	//fastIO;
	int y,m,d;
	scanf("%d/%d/%d",&y,&m,&d);
	if(y > 2019 || m > 4)
		cout << "TBD\n";
	else
		cout << "Heisei\n";
	return 0;
}