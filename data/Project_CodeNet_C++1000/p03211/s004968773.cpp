#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	int N = S.size();
	int tmp = 999;
	rep(i,N-2){
		string T = S.substr(i,3);
		rep(j,3){
			int num = (T[0]-'0')*100 + (T[1]-'0')*10 + (T[2]-'0');
		    if(tmp>abs(753-num)) {
				tmp = abs(753-num);
			}
		}
	}
	cout << tmp << endl;
}








