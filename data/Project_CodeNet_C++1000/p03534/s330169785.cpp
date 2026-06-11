#include <bits/stdc++.h>
using namespace std;
int main(){
	string S; 
	cin >> S; 
	int A = 0, B = 0, C = 0; 
	int N = S.size(); 
	for(int i = 0; i < N; i++){
		if(S.at(i) == 'a') A ++; 
		if(S.at(i) == 'b') B ++; 
		if(S.at(i) == 'c') C ++; 
	}
	if(max({A, B, C}) - min({A, B, C}) <= 1) cout << "YES" << endl; 
	else cout << "NO" << endl; 
}