#include <bits/stdc++.h>

using namespace std;

vector<int> buf;
vector<bool> seen;
vector<string> ss;

void dfs(int i, const int size, const int range_start, const int range_end)
{
	if (i == size) {
		string str;
		// ここで所望の作業を行う
		for (int j = 0; j < buf.size(); j++) {
			//			cout << buf[j];
			str.push_back((char)(buf[j] + 48));
		}
		//		cout << endl;
		ss.push_back(str);
	}
	else {
		for (int j = range_start; j <= range_end; j++) {
			buf[i] = j;
			dfs(i + 1, size, range_start, range_end);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
//	sort(a.begin(), a.end());
	

	vector<int> l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	//！！重複なし！！
	//range_start~~range_end、桁数sizeの組み合わせを作る
	//size：桁数
	//ss:組み合わせ結果の配列(string)

	int size = n;
	int range_start = 0;
	int range_end = 3;

	buf.resize(size);
	seen.resize(range_end + 1);

	dfs(0, size, range_start, range_end);

	int minn = 1000000;

	for (int i = 0; i < ss.size(); i++) {

		bool zeroflg = false;
		bool ichiflg = false;
		bool niflg = false;
		for (int j = 0; j < n; j++) {
			if (ss[i][j] == '0') { zeroflg = true; }
			else if (ss[i][j] == '1') { ichiflg = true; }
			else if (ss[i][j] == '2') { niflg = true; }
		}
		if (zeroflg == false || ichiflg == false || niflg == false) { continue; }

		int aa = 0;
		int bb = 0;
		int cc = 0;
		int mp = 0;

		for (int j = 0; j < n ; j++) {
			if (ss[i][j] == '0') {
				if (aa != 0) { mp += 10; }
				aa += l[j];
			}
			else if (ss[i][j] == '1') {
				if (bb != 0) { mp += 10; }
				bb += l[j];
			}
			else if (ss[i][j] == '2') {
				if (cc != 0) { mp += 10; }
				cc += l[j];
			}
		}
		mp += abs(a[0] - aa) + abs(a[1] - bb) + abs(a[2] - cc);

		minn = min(minn, mp);

//	cout << ss[i] << " " << aa << " " << bb << " " << cc << " " << mp << endl;
	}

	cout << minn << endl;

	return 0;
}