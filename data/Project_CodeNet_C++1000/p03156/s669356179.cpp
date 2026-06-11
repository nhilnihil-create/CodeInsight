#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n;
	int a,b;
	int p[100];
	
	cin	>> n;
	cin >> a >> b;
	for(int i=0;i<n;i++) cin >> p[i];

	int t=0,u=0,v=0;
	for(int i=0;i<n;i++){
		if(p[i]<=a){
			t++;
		}else if(a<p[i]&&p[i]<=b){
			u++;
		}else if(b<p[i]){
			v++;
		}
	}
	
	cout << min(min(t,u),v) << endl;


	return 0;
}
