#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

struct S
{
    ll m_n1;
    int m_n2;
    int m_n3;
	int m_n4;

    S(ll n1, int n2, int n3, int n4) : m_n1(n1), m_n2(n2), m_n3(n3), m_n4(n4)
    {
    }

    bool operator<(const struct S& other) const
    {
        return m_n1 < other.m_n1;
    }
};

bool visited[1005][1005][1005];
 
int main () {
	int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
	vector<ll> vx(X), vy(Y), vz(Z);
	rep(i,X) {
		cin >> vx[i]; 
	}
	rep(i,Y) {
		cin >> vy[i]; 
	}
	rep(i,Z) {
		cin >> vz[i]; 
	}
	sort(vx.rbegin(), vx.rend());
	sort(vy.rbegin(), vy.rend());
	sort(vz.rbegin(), vz.rend());
	priority_queue< S > pq;
	int x, y, z;
	ll del;
	pq.push(S(vx[0] + vy[0] + vz[0], 0, 0, 0));
	visited[0][0][0] = true;
	rep(i,K) {
		auto cur = pq.top();
		pq.pop();
		del = cur.m_n1;
		x = cur.m_n2;
		y = cur.m_n3;
		z = cur.m_n4;
		cout << del << endl;
		int nx = min(X-1, x+1);
		int ny = min(Y-1, y+1);
		int nz = min(Z-1, z+1);
		if (!visited[nx][y][z]) {
			pq.push(S(vx[nx] + vy[y] + vz[z], nx, y, z));
			visited[nx][y][z] = true;
		}
		if (!visited[x][ny][z]) {
			pq.push(S(vx[x] + vy[ny] + vz[z], x, ny, z));
			visited[x][ny][z] = true;
		}
		if (!visited[x][y][nz]) {
			pq.push(S(vx[x] + vy[y] + vz[nz], x, y, nz));
			visited[x][y][nz] = true;
		}
	}
    return 0;
}