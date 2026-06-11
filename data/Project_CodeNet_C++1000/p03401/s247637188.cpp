#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
	int n;cin>>n;
	vector<int> v(n+2);
	v[0]=0;v.back()=0;
	for(int i=1;i<=n;i++)cin>>v[i];
	vector<int> d(n+2);
	for(int i=0;i<=n;i++)d[i]=abs(v[i+1]-v[i]);
	int sum=accumulate(d.begin(),d.end(),0);
	for(int i=1;i<=n;i++){
	    cout<<sum-d[i-1]-d[i]+abs(v[i-1]-v[i+1])<<endl;
	}
	
}