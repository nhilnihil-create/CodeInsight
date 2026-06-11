#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int x){
	bitset<40000> aset;
	aset[20000] = 1;
	int n = a.size();
	for(int i = 0;i < n;i++){
		bitset<40000> bset;
		bset |= aset << a[i];
		bset |= aset >> a[i];
		swap(aset, bset);
	}
	if(aset[20000+x])return 1;
	return 0;
}

int main(){
	vector<int> a, b;
	string str;
	int f = 0, sum = 0, from, x, y;
	cin >> str >> x >> y;
	str.push_back('T');
	
	for(from = 0;from < str.size();from++, x--){
		if(str[from] == 'T')break;
	}
	for(int i = from;i < str.size();i++){
		if(str[i] == 'T' && sum){
			if(f == 0)a.push_back(sum);
			else b.push_back(sum);
			sum = 0;
		}
		if(str[i] == 'F')sum++;
		if(str[i] == 'T')f = !f;
	}
	
	int t1 = solve(a, x);
	int t2 = solve(b, y);
	if(t1 && t2)printf("Yes\n");
	else printf("No\n");
	return 0;
}