#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <string>
using namespace std;
typedef long long int ll;

int main(){
	int n,a,b; cin >> n >> a >> b;
	vector<int> p(n);
	int cnt=0;
	int cnt1=0;
	for(int i=0;i<n;i++){
		cin >> p[i];
		if(p[i]<=a)cnt++;
		if(p[i]>b)cnt1++;
	}
	cout << min(min(cnt,cnt1),n-cnt-cnt1) << endl;
}