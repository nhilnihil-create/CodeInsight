#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int A, B; cin >> A >> B;
    cout << 100 << " " << 100 << endl;
    char grid[110][110];
    rep(i, 100) {
        rep(j, 100) {
            if(i < 50) grid[i][j] = '.';
            else grid[i][j] = '#';
        }
    }
    A --; B --;
    int k = 100 - 1, l = 100 - 1;
    while(A > 0) {
        grid[k][l] = '.';
        A --;
        l -= 2;
        if(l < 0) {
            if(k % 2 == 1) {
                k -= 2;
                l = 98;
            } else {
                k -= 2;
                l = 99;
            }
        }
    }
    k = 0, l = 0;
    while(B > 0) {
        grid[k][l] = '#';
        B --;
        l += 2;
        if(l >= 100) {
            if(k % 2 == 0) {
                k += 2;
                l = 1;
            } else {
                k += 2;
                l = 0;
            }
        } 
    }
    rep(i, 100) {
        rep(j, 100) {
            cout << grid[i][j];
        }
        cout << endl;
    }
	return 0;
}