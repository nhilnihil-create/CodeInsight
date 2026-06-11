#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	set<string> shiritori;
	string S, T;
	cin >> S;
	shiritori.insert(S);
	bool ok = true;
	for(int i = 2;i <= N; i++){
		cin >> T;
		if(shiritori.count(T)){
			ok = false;
		}
		if(T[0] != S[S.size()-1]) ok = false;
		shiritori.insert(T);
		S = T;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;

}








