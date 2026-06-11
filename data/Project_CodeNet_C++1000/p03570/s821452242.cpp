#include <bits/stdc++.h>
using namespace std;
int main(){
	string S; cin >> S; 
	int N = S.size(); 
	vector<int> M(67108864); 
	int A[200010] = {}; 
	bool odd[30] = {}; 
	for(int i = 1; i <= N; i++){
		int c = S.at(i-1) - 'a'; 
		if(odd[c]){
			A[i] = A[i-1] - (1 << c); 
			odd[c] = false; 
		}
		else{
			A[i] = A[i-1] + (1 << c); 
			odd[c] = true; 
		}
	}
	M[0] = 1; 
	for(int i = 1; i <= N; i++){
		int tmp = 1145141919;
		if(M[A[i]]) tmp = M[A[i]];  
		for(int j = 0; j < 26; j++){
			if(((A[i] >> j) & 1) && M[A[i] - (1 << j)]){
				tmp = min(tmp, M[A[i] - (1 << j)] + 1); 
			}
			if(!((A[i] >> j) & 1) && M[A[i] + (1 << j)]){
				tmp = min(tmp, M[A[i] + (1 << j)] + 1); 
			}
		}
		M[A[i]] = tmp;
	}
	cout << max(M[A[N]] - 1, 1) << endl; 
}