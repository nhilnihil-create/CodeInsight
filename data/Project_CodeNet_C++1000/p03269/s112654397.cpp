#include <iostream>
#include <vector>
using namespace std;
vector <pair<pair<int,int>,int> > v;
int main(int argc, char** argv) {
	int x;
	cin >> x;
	--x;
	if(!x)
	{
		cout << "2 1\n1 2 0";
		return 0;
	}
	int now=1,n=1;
	while((now<<1)<=x+1) now<<=1,++n;
	cout << n << " ";
	int W=1;
	for(int i=n-1;i>=1;i--)
	{
		v.push_back({{i,i+1},W});
		v.push_back({{i,i+1},0});
		W<<=1;
	}
	x^=W,now=1;
	int qwq=W;
	++x;
	while(W)
	{
		W>>=1,++now;
		if(x&W)
			v.push_back({{1,now},qwq}),x^=W,qwq+=W;
	}
	cout << v.size() << "\n";
	for(auto x:v) cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
	return 0;
}