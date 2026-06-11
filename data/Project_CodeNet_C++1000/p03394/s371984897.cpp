#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vt;
vector<int> vt1;
vector<int> vt2;
vector<int> dap;
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 3)
	{
		printf("2 5 63");
		return 0;
	}
	for (int i = 8; i <= 30000; i += 2) {
		if (i % 6 == 0)continue;
		vt.push_back(i);
	}
	for (int i = 15; i <= 30000; i += 6)
		vt1.push_back(i);
	for (int i = 6; i <= 30000; i+=6)
		vt2.push_back(i);
	int ch = 0;
	dap.push_back(2); dap.push_back(4);
	dap.push_back(3); dap.push_back(9);
	n -= 4;
	for (int i = 0; i < vt.size(); i+=2)
	{
		if (n / 2 == 0)break;
		dap.push_back(vt[i]); dap.push_back(vt[i + 1]);
		n -= 2;
	}
	for (int i = 0; i < vt1.size(); i += 2)
	{
		if (n / 2 == 0)break;
		dap.push_back(vt1[i]); dap.push_back(vt1[i + 1]);
		n -= 2;
	}
	for (int i = 0; i < vt2.size(); i += 2)
	{
		if (n / 2 == 0)break;
		dap.push_back(vt2[i]); dap.push_back(vt2[i + 1]);
		n -= 2;
	}
	sort(dap.begin(), dap.end());
	if (n)
		dap.push_back(30000);
	for (int i = 0; i < dap.size(); i++)
		printf("%d ", dap[i]);
}