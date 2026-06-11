#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N;
int a[SIZE];
ll K;

int main()
{
	cin >> N;
	int amin = INF,amax=-INF;
	int argmin,argmax;
	rep(i,0,N){
		cin >> a[i];
		if(amin > a[i]){
			amin = a[i];
			argmin = i;
		}
		if(amax < a[i]){
			amax = a[i];
			argmax = i;
		}
	}
	cout << (N-1)*2 << endl;
	if(abs(amax) >= abs(amin)){
		rep(i,0,N) if(i != argmax){
			cout << argmax+1 << " " << i+1 << endl;
		}
		rep(i,0,N-1){
			cout << i+1 << " " << i+1+1 << endl;
		}
	}else{
		rep(i,0,N) if(i != argmin){
			cout << argmin+1 << " " << i+1 << endl;
		}
		rep(i,0,N-1){
			cout << N-i << " " << N-i-1 << endl;
		}
	}


	return 0;
}
