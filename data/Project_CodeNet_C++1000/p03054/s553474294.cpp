#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
	int H,W,N;
	cin >> H >> W >> N;
	int sr,sc;
	cin >> sr >> sc;
	string S,T;
	cin >> S;
	cin >> T;


	int now;
	//先攻：左　後攻：右
	now=sc;
	for(int i=0; i<N; i++){
		if(S[i]=='L'){
			now--;
			if(now<1){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(T[i]=='R' && now<W){
			now++;
		}
	}

	//先攻：右　後攻：左
	now=sc;
	for(int i=0; i<N; i++){
		if(S[i]=='R'){
			now++;
			if(now>W){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(T[i]=='L' && now>1){
			now--;
		}
	}

	//先攻：上　後攻：下
	now=sr;
	for(int i=0; i<N; i++){
		if(S[i]=='U'){
			now--;
			if(now<1){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(T[i]=='D' && now<H){
			now++;
		}
	}

	//先攻：下　後攻：上
	now=sr;
	for(int i=0; i<N; i++){
		if(S[i]=='D'){
			now++;
			if(now>H){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(T[i]=='U' && now>1){
			now--;
		}
	}

	cout << "YES" << endl;
	return 0;
}