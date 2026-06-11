#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
	vector<int> p(4);
	cinf(4,p);
	bool a=false;
    bool b=false;
    bool c=false;
  	bool d=false;
	for(int i=0;i<4;i++){
		if(p[i]==1)a=true;
		if(p[i]==9)b=true;
		if(p[i]==7)c=true;
		if(p[i]==4)d=true;
	}
	cout << (a&&b&&c&&d?"YES":"NO") << endl;
}