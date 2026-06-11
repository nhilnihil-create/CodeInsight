#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){	
	
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> p(n);
	int mi=0,mdl=0,la=0;
	for(int i=0;i<n;i++){
		cin >> p[i];
		if(p[i]<=a){
			mi++;
		}else if(p[i]>b){
			la++;
		}else{
			mdl++;
		}
	}
	int ans=min({mi,mdl,la});
	cout << ans << endl;
	
	return 0;
}
