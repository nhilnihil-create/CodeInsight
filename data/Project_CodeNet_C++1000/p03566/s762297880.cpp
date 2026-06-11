#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> t(N);
	for(int i=0; i<N; ++i){
	    cin >> t[i];
	    t[i] *= 2;
	}
	map<int, int> diag, diah, diai;
	double sum=0.0;
	for(int i=0; i<N; ++i){
	    int v; cin >> v;
	    diah[sum]=diag[sum]=min(diag[sum], v*2);
	    for(int p=1; p<=t[i]; ++p) diah[sum+p]=diag[sum+p]=v*2;
	    sum += t[i];
	}
	diag[0]=0;
	for(int d=1; d<=sum; ++d) diag[d]=min(diag[d-1]+1, diag[d]);
	diah[sum]=0;
	for(int d=sum-1; d>=0; --d) diah[d]=min(diah[d+1]+1, diah[d]);
	for(int d=0; d<=sum; ++d) diai[d]=min(diag[d], diah[d]);
	double ans=0.0;
	for(int d=1; d<=sum; ++d) ans += (double) (diai[d-1]+diai[d])/8;
	cout << setprecision(15) << ans << endl;
	return 0;
}
