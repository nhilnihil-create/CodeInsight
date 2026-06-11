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
	
	string S;
	cin >> S;
	
	int cnt[3];
	for(int i=0;i<3;i++) cnt[i] = 0;
	
	for(int i=0;i<S.length();i++) cnt[S[i] - 'a']++;
	
	sort(cnt, cnt + 3);
	
	//cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
	
	if(cnt[0] == cnt[1] && cnt[1] == cnt[2]){
		cout << "YES" << endl;
		return 0;
	}
	if(cnt[0] == cnt[1] && cnt[1] == cnt[2] - 1){
		cout << "YES" << endl;
		return 0;
	}
	if(cnt[0] == cnt[1] - 1 && cnt[1] == cnt[2]){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	
    return 0;
}