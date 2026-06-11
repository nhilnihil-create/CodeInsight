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
	
	int N,H,W;
	cin >> N >> H >> W;
	vector<int> A(N),B(N);
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
	}
	
	int cnt = 0;
	for(int i=0;i<N;i++){
		if(H <= A[i] && W <= B[i]) cnt++;
	}
	
	cout << cnt << endl;
	
	
	
	
    return 0;
}