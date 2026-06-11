// B - Touitsu
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,e)

int main(){
	int N; cin>>N;
	string A,B,C; cin>>A>>B>>C;
	int count = 0;
	rpz(i, N) count += set<int>{A[i],B[i],C[i]}.size() - 1;
	cout<< count <<endl;
}