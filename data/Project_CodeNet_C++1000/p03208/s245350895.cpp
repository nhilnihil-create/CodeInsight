
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double> 
#define pi acos(-1)
#define mod 1000000007


using namespace std;
int arr[200005];


int main() {
	HS
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int mini = 1e9;
	for (int i = 0; i <n; i++)
	{
		if(arr[i+k-1])
		mini = min(mini, arr[i + k-1] - arr[i]);
	}
	cout << mini << endl;
	return 0;
}