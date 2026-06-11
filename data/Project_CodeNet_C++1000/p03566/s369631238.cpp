#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <sys/timeb.h>
#include <cstdio>
#include <sys/time.h>

using namespace std;
#define ll long long
#define uint unsigned int
#define ulong unsigned long long int

template<typename T> bool InRange(T t, T l, T r){ return l <= t && t < r; }

int main(){
	
	int N;
	cin >> N;
	vector<int> T(N),V(N);
	for(int i=0;i<N;i++) cin >> T[i];
	for(int i=0;i<N;i++) cin >> V[i];
	
	vector<int> H(N+1);
	int Inf = (int) 1e9;
	for(int i=1;i<N;i++) H[i] = Inf;
	for(int i=0;i<N;i++){
		H[i] = min(H[i], V[i]);
		H[i+1] = min(H[i+1], H[i] + T[i]);
		H[i+1] = min(H[i+1], V[i]);
	}
	for(int i=N;i>0;i--){
		H[i] = min(H[i], V[i - 1]);
		H[i-1] = min(H[i-1], H[i] + T[i-1]);
		H[i-1] = min(H[i-1], V[i - 1]);
	}
//for(int i=0;i<N+1;i++) cout << H[i] << " "; cout << endl;	
	double tot = 0;
	for(int i=0;i<N;i++){
		int l = V[i] - H[i];
		int r = V[i] - H[i + 1];
		if(l + r > T[i]){
			double t0 = -1.0 * (double) (H[i] - T[i] - H[i+1]) / 2.0;
			tot += t0 * (H[i] + H[i] + t0) / 2.0;
			tot += (T[i] - t0) * (H[i + 1] + H[i + 1] + (T[i] - t0)) / 2.0;
		} else {
			tot += V[i] * (T[i] - l - r);
			tot += (double) l * (H[i] + H[i] + l) / 2.0;
			tot += (double) r * (H[i + 1] + H[i + 1] + r) / 2.0;
		}
//cout << "tot: " << tot << endl;
	}
	
	//cout << tot << endl;
	printf("%.12f\n", tot);
	
    return 0;
}
