#include        <bits/stdc++.h>
using namespace std;

struct	QS {
	long L=0;
	long R=0;
};

int     main() {
	string	S;
	cin >>S;
	int N=S.size();
	vector<long> P3(N+1);
	P3.at(0)=1;
	for (int i=1; i<=N; i++) 
		P3.at(i)=(P3.at(i-1)*3)%1000000007;
	// Q
	vector<QS> Q(N);
	Q.at(0).L=0;
	for (int i=1; i<N; i++) {
		Q.at(i).L=Q.at(i-1).L;
		if ('?'==S.at(i-1)) Q.at(i).L++;
	}
	Q.at(N-1).R=0;
	for (int i=N-2; i>=0; i--) {
		Q.at(i).R=Q.at(i+1).R;
		if ('?'==S.at(i+1)) Q.at(i).R++;
	}
	// A
	vector<int> A(N, 0);
	A.at(0)=0;
	for (int i=1; i<N; i++) {
		A.at(i)=A.at(i-1);
		if ('A'==S.at(i-1)) A.at(i)++;
	}
	// C
	vector<int> C(N, 0);
	C.at(N-1)=0;
	for (int i=N-2; 0<=i; i--) {
		C.at(i)=C.at(i+1);
		if ('C'==S.at(i+1)) C.at(i)++;
	}
	long SSS=0;
	for (int i=1; i<N-1; i++) {
		if ('A'==S.at(i)) continue;
		if ('C'==S.at(i)) continue;
		long LL = A.at(i)*P3.at(Q.at(i).L);
		LL %= 1000000007;
		if (Q.at(i).L>0) {
			LL += Q.at(i).L * P3.at(Q.at(i).L-1);
			LL %= 1000000007;
		}
		long RR = C.at(i)*P3.at(Q.at(i).R);
		RR %= 1000000007;
		if (Q.at(i).R>0) {
			RR += Q.at(i).R * P3.at(Q.at(i).R-1);
			RR %= 1000000007;
		}
		SSS += (LL*RR)%1000000007;
		SSS %= 1000000007;
	}
	cout << SSS << endl;
	return 0;
};
