#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int ALL,ADD;;
	ALL=ADD=1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]%2==0){
			ADD*=2;
		}else{
			ADD*=1;
		}
		ALL*=3;
	}
	cout << ALL-ADD << endl;
	return 0;
}
