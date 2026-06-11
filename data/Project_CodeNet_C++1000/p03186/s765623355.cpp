#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int A, B, C;
	cin >> A >> B >> C;
	if(C>A+B) cout << A+2*B+1 << endl;
	else if (C==A+B) cout << A+2*B << endl;
	else cout << B + C << endl;	

}











