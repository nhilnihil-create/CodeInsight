#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX 100

int t[MAX+2], v[MAX+2], s[MAX+2];

double f(int i, double t){
	if(i>0 && t<=s[i-1]) return v[i]+(s[i-1]-t);
	else if(t<=s[i]) return v[i];
	else return v[i]+(t-s[i]);
}

int main(){
	int n;
	cin >> n;
	t[0]=0, v[0]=0;
	t[n+1]=0, v[n+1]=0;
	for(int i=1; i<=n; i++) cin >> t[i];
	for(int i=1; i<=n; i++) cin >> v[i];

	s[0]=t[0];
	for(int i=1; i<=n+1; i++) s[i]=s[i-1]+t[i];

	double ans=0.0;
	for(int i=0; i<2*s[n+1]; i++){
		double f1=100.0, f2=100.0;
		for(int j=0; j<=n+1; j++) f1=min(f1, f(j, i/2.0));
		for(int j=0; j<=n+1; j++) f2=min(f2, f(j, (i+1)/2.0));
		ans+=(f1+f2)/4.0;
	}
	printf("%.9f\n", ans);
	return 0;
}