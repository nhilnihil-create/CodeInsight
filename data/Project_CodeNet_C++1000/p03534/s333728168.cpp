#include <bits/stdc++.h>
using namespace std;

int main(void){
	string S;
	cin >> S;
	vector<int> cnt(3);
	for(int i=0;i<S.size();i++){
		if(S[i]=='a')cnt[0]++;
		else if(S[i]=='b')cnt[1]++;
		else cnt[2]++;
	}
	sort(cnt.begin(),cnt.end());
	if(cnt[2]-cnt[0]<=1){
		cout << "YES" << endl;
	}else cout << "NO" << endl;
}