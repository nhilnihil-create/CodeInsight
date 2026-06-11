#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int H, W, N; 
	cin >> H >> W >> N; 
	pair<int, int> A[400010] = {}; 
	pair<int, int> C[400010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> A[i].first >> A[i].second; 
		C[i].first = A[i].second; C[i].second = A[i].first; 
	}
	for(int i = N; i < N+W; i++){
		A[i].first = H + 1; A[i].second = i - N + 1;
		C[i].first = A[i].second; C[i].second = A[i].first; 
	}
	sort(A, A+N); 
	sort(C, C+N+W); 
	int mashita = C[0].second; 
	int sugumigi = 0; 
	pair<int, int> S; 
	S.first = 2, S.second = 2; 
	int D = lower_bound(C, C+N+W, S) - C; 
	for(int i = 0; i < H; i++){
		if(C[D+i].first != 2 || C[D+i].second != 2 + i){
			sugumigi = 2 + i; break; 
		}
	}
	int ans = 0; 
    int dif = 1 - sugumigi; 
	if(mashita == 2){ans = 1;}
	else if(mashita <= sugumigi){ans = mashita - 1;}
	else{
		bool kiwadoi = false; 
		for(int i = 0; i < N + W; i++){
            pair<int, int> Q; 
            Q.first = A[i].second; Q.second = A[i].first;  
			if(A[i].first < sugumigi || 
				A[i].second - A[i].first > dif + 1){continue;}
			else if(A[i].second - A[i].first == dif + 1){kiwadoi = true;}
            else if(A[i].second - A[i].first < dif && 
                    (C[(lower_bound(C, C+N+W, Q) - C) - 1].first != A[i].second
                      || C[(lower_bound(C, C+N+W, Q) - C) - 1].second != A[i].first - 1)){
				ans = A[i].first - 1; break; 
			}
			else if(A[i].second - A[i].first < dif && 
                    (C[(lower_bound(C, C+N+W, Q) - C) - 1].first == A[i].second
                      && C[(lower_bound(C, C+N+W, Q) - C) - 1].second == A[i].first - 1)){
				dif = A[i].second - A[i].first; 
			}
            else if(kiwadoi && A[i].second - A[i].first == dif){
				dif --; 
			}
			else if(!kiwadoi && A[i].second - A[i].first == dif){
				ans = A[i].first - 1; break; 
			}
		}
	}
    cout << ans << endl; 
}