#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define REPI(_i,len) for(int _i=0;_i<len;++_i)
#define REPI2(_i,_l,len) for(int _i=0,_l=len;_i<_l;++_i)
#define VREP(v,_itr,_end) for(auto _itr=v.begin(),_end=v.end();_itr!=_end;++_itr)
#define VCREP(v,_itr,_end) for(auto _itr=v.cbegin(),_end=v.cend();_itr!=_end;++_itr)
#define TST(st) typedef struct st st;

int abs(int x, int y) {
	return x >= 0 ? x : -x;
}

int main() {
	int N;
	cin >> N;

	vi a(N),b(N),c(N);
	REPI(i,N)
		cin >> a[i] >> b[i] >> c[i];

	vi aMax(N),bMax(N),cMax(N);

	REPI(i,N){
		if(i==0){
			aMax[0]=a[0];
			bMax[0]=b[0];
			cMax[0]=c[0];
			continue;
		}
		aMax[i]=a[i]+max(bMax[i-1],cMax[i-1]);
		bMax[i]=b[i]+max(cMax[i-1],aMax[i-1]);
		cMax[i]=c[i]+max(aMax[i-1],bMax[i-1]);
	}
	int max=aMax[N-1];
	if(max<bMax[N-1]){
		max=bMax[N-1];
	}
	if(max<cMax[N-1]){
		max=cMax[N-1];
	}
	cout<<max<<endl;

	return 0;
}