#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int used[100];

int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > red(n), blue(n);
	for (int i = 0; i < n; i++){
		cin >> red[i].first >> red[i].second;
	}
	for (int i = 0; i < n; i++){
		cin >> blue[i].second >> blue[i].first;
	}
	sort(red.begin(), red.end(), greater<pair<int, int> >());
	sort(blue.begin(), blue.end());

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (red[j].first < blue[i].second && red[j].second < blue[i].first && !used[j]){
				used[j] = true;
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

