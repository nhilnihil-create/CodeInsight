#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
namespace fio {
	streambuf* in = cin.rdbuf();
	char bb[1000000], * s = bb, * t = bb;
#define gc() (s==t&&(t=(s=bb)+in->sgetn(bb,1000000),s==t)?EOF:*s++)
	inline int read() {
		int x = 0;
		char ch = gc();
		while (ch < 48)ch = gc();
		while (ch >= 48)x = x * 10 + ch - 48, ch = gc();
		return x;
	}
}using fio::read;
int sst[100005];
int k;
queue<int>ygy;
int main() {
	cin >> k;
	ygy.push(1), memset(sst, 0x3f, sizeof(sst)), sst[1] = 1;
	while (ygy.size()) {
		int thx = ygy.front(); ygy.pop();
		if (sst[thx] > sst[0])continue;
		if (sst[(thx + 1) % k] > sst[thx] + 1)sst[(thx + 1) % k] = sst[thx] + 1, ygy.push((thx + 1) % k);
		if (sst[thx * 10 % k] > sst[thx])sst[thx * 10 % k] = sst[thx], ygy.push(thx * 10 % k);
	}
	cout << sst[0];
}