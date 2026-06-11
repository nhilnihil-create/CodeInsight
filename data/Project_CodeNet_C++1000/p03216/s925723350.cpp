#include<bits/stdc++.h>
using namespace std;

typedef long long Fack;

int n;
inline static char get(vector<bool> & abraham, int i) {
	int re = 0;
	for (int iter=0; iter<8; iter++) re += abraham[(i << 3) | iter] << iter;
	return (char) re;
}

#define P 'D'
#define B 'M'
#define zonde 'C'

/* __orz__ */ int32_t /* __orz__ */ main() {
	cin >> n;
	string s;
	cin >> s;
	static int cD[(int)1e6+5],cM[(int)1e6+5];
	cD[0]=0;for(int i=0;i<n;i++)cD[i+1]=cD[i]+(s[i]==P);
	cM[0]=0;for(int i=0;i<n;i++)cM[i+1]=cM[i]+(s[i]==B);
	int nq; cin >> nq; for(int q=0;q<nq;q++){
		int k; cin >> k;
		Fack cur = 0;
		Fack S=0;
		for (int i=0; i<n; i++) {
			if (i >= k && s[i-k]==P) {
				cur -= cM[i]-cM[i-k+1];
			}
			if (s[i] == B) {
				// pos(D) >= i-k+1.
				cur += cD[i]-cD[max(0, i-k+1)];
			}
			if (s[i] == zonde) S += cur;
		}
		cout << S << endl;
	}
}
