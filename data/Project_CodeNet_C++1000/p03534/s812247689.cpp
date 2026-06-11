#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
	vector<int> count(3,0);
	for(int i=0;i<S.size();i++)count[S[i]-'a']++;
	sort(count.begin(),count.end());
	if(count[2]-count[0]<=1)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}