#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{	
	int N;
	cin >> N;

	vector<int> A(N);
	rep(i, N) cin >> A[i];

	vector<int> B(N);
	rep(i, N) cin >> B[i];

	ll sumA = 0;
	rep(i, N) sumA += A[i];

	ll sumB = 0;
	rep(i, N) sumB += B[i];

	if (sumA < sumB)
	{
		cout << -1;
		return 0;
	}

	ll count = 0;

	ll over = 0;
	vector<ll> overs;
	ll under = 0;

	rep(i, N)
	{
		if (A[i] < B[i])
		{
			count++;
			under += B[i] - A[i];
		}
		else if(A[i] > B[i])
		{
			overs.push_back(A[i] - B[i]);
		}
	}

	//降順
	sort(all(overs), greater<ll>());

	for (auto over : overs)
	{
		if (under <= 0) break;

		under -= over;

		count++;
	}

	cout << count << endl;

	return 0;
}