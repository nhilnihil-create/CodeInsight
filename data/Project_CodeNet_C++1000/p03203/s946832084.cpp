#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<complex>

using namespace std;
queue<long long int>que[200005];
long long int num[200005],h,w,n,x[200001],y[200001],res=9999999,can=0;
pair<long long int ,long long int>pa[200005];
const long long int mod=1000000007;
int main(){
	cout << fixed << setprecision(18);
	string str[300];
	cin>>h>>w>>n;
	res=h;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		pa[i].first=x[i];
		pa[i].second=y[i];
	}
	sort(pa+1,pa+n+1);
	for(int i=1;i<=n;i++){
		if(pa[i].first==pa[i].second-can){
			can=can-1;	
		}else if(pa[i].first>pa[i].second-can){
			cout<<pa[i].first-1<<endl;
			return 0;	
		}
		
	}
	cout<<res<<endl;
}
