#include <bits/stdc++.h>
using namespace std;

bitset<4000000> bs;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	bs[0] = 1;
	int n; cin >> n;
	int s = 0;
	while(n--){
		int x; cin >> x;
		s += x;
		bs |= (bs << x);
	}
	
	s = (s + 1)/2;
	while(!bs[s]) s++;
	cout << s;
}
