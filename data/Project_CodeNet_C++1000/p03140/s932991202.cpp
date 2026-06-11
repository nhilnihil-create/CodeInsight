// B - Touitsu
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,e)

int main(){
	int N; cin>>N;
	string A,B,C; cin>>A>>B>>C;
	int count = 0;
	rpz(i, N){
		char a = A[i], b = B[i], c = C[i];
		if(a==b && b==c) count += 0;
		else if(a==b || a==c || b==c) count += 1;
		else count += 2;
	}
	cout<< count <<endl;
}