#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string s;
int x, y;
const int OFFSET = 10000;
bitset<2*OFFSET+10> xx,yy;

void solve()
{
    const int n = s.length();
	int step = 0;
	bool f = true; // x axis
	bool fi = true;
	xx.set(OFFSET);
	yy.set(OFFSET);
	for(int i=0;i<=n;++i){
		if(s[i] == 'F') step++;
		else{
			auto& t = f ? xx : yy;
			if(fi) t<<=step;
			else t=(t<<step)|(t>>step);
			fi = false;
			step = 0;
			f ^= 1;
		}
	}
	if(xx.test(x+OFFSET)&&yy.test(y+OFFSET)) cout<<"Yes\n";
	else cout<<"No\n";
}

int main()
{
	cin >> s;
	cin >> x >> y;
	solve();
	return 0;
}