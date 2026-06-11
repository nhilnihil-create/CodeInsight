#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int a, b, k;
	set<int> q;
	cin >> a >> b >> k;
	rep(i, k){
		if(a+i <= b)q.insert(a + i);
	}
	for(int i = k-1; i >= 0; i--){
		if(b-i >= a)q.insert(b - i);
	}
	for(auto i = q.begin(); i != q.end(); i++) cout << *i << endl;
    return 0;
}