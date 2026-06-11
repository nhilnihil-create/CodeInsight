#include"bits/stdc++.h"
using namespace std;

const vector<int> dx = { 1,0,-1,0,1,-1,-1,1 };
const vector<int> dy = { 0,1,0,-1,1,1,-1,-1 };

int main() {
	int H, W; cin >> H >> W;
	vector<string> field(H);
	for (int i = 0; i < H; i++)
	{
		cin >> field.at(i);
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (field.at(i).at(j) == '#')continue;

			char cnt = '0';
			for (int k = 0; k < 8; k++)
			{
			int nx = j + dx.at(k);
			int ny = i + dy.at(k);

			if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;
			if (field.at(ny).at(nx) == '#') cnt = 1 + cnt;
			}
			field.at(i).at(j) = cnt;
		}
	}
	for (int i = 0; i < H; i++)
	{
		cout << field.at(i) << endl;
	}
}