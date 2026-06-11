#include <bits/stdc++.h>
using namespace std;
int main(){
	string S;
	cin >> S;
    int ans = 753;
    string T;
	for(int i = 0; i < S.size()-2; i++) {
		T=S.substr(i,3);
		ans = min(ans,abs(753-((T[0]-'0')*100+(T[1]-'0')*10+(T[2]-'0'))));
	}
	cout<< ans <<endl;
}
