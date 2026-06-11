#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
bool isPrime[1000010];

void set_prime() {
    for(int i = 0; i <= 1000010; i++) isPrime[i] = true;
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < 2000; i++) {
		int j = 2;
		while (i * j <= 1000000) {
			isPrime[i*j] = false;
			j++;
		}
	}
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    set_prime();
    vector<int> v;
    REP(i, 7, 55555) {
        if(isPrime[i] && i % 5 == 1) {
            v.push_back(i);
        }
    }
    rep(i, N) {
        if(i != 0) cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}
