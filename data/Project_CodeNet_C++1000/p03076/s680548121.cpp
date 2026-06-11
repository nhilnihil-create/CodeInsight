#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef long long int ll;

const ll maxN = 1e7;
const ll INF = 1e17;

ll xs[] = {-1, 1, 0, 0};
ll ys[] = {0, 0, -1, 1};

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll a[5];
	for(ll i=0; i<5; i++)
		cin >> a[i];
	string st = "01234";
	ll mn = INF;
	do{
		ll cur = 0;
		for(ll i=0; i<4; i++){
			cur += a[st[i]-'0'];
			if(cur%10 != 0)
				cur += 10-(cur%10);
		}
		mn = min(mn, cur + a[st[4]-'0']);
	}while(next_permutation(begin(st), end(st)));
	cout << mn;
	return 0;
}