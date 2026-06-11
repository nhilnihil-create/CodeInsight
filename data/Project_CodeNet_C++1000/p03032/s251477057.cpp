#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <tuple>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[])
{
    int n, k, i, j, l;
	cin >> n >> k;
	vector<int> value(n);
	vector<int> invent;
	int mini = min(n, k);
	int answer = 0;
	int now = 0;
	for (i = 0; i < n; i++)
		cin >> value[i];

	for (i = 0; i <= mini; i++) {
		for (j = 0; j <= mini - i; j++) {
			now = 0;
			invent.erase(invent.begin(), invent.end());			
			for (l = 0; l < i; l++)
				invent.push_back(value[l]);
			for (l = 0; l < j; l++)
				invent.push_back(value[n - l - 1]);
			sort(invent.begin(), invent.end());
			for (l = 0; l < k - i - j && l < invent.size(); l++) {
				if (invent[l] <= 0) 
					invent[l] = 0;
				else
					break;
			}
			for (l = 0; l < invent.size(); l++)
				now += invent[l];
			if (now > answer)
				answer = now;
		}
	}
	cout << answer << endl;
						 
	return 0;
}
