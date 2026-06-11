#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

typedef pair<int, int> P;


int main()
{	
	//解答方針
	
	int n, k;
	cin >> n >> k;

	priority_queue<P, vector<P>, function<bool(P, P)>> ps([](P a, P b) {return a.second < b.second; });	
	rep(i, n)
	{
		int t, d;
		cin >> t >> d;
		ps.emplace(t, d);
	}

	priority_queue<P, vector<P>, function<bool(P, P)>> ks([](P a, P b) {return a.second > b.second; });
	map<int, int> counts;
	ll score = 0;

	//最初のk個をとる
	rep(i, k)
	{
		P p = ps.top(); ps.pop();
		score += p.second;
		counts[p.first]++;

		ks.push(p);
	}

	score += (ll)counts.size() * (ll)counts.size();

	//残りのn - k個を入れ替えながら、満足度の最大値を計算
	ll maxScore = score;
	while (!ps.empty())
	{
		P p = ps.top(); ps.pop();

		//すでにk個のなかに同じ種類の寿司がある場合は
		//寿司の種類が増えないので置き換えない
		if (counts.find(p.first) != counts.end()) continue;

		//k個の中でおいしさ最小の寿司を交換
		P kp;
		bool found = false;

		while (!ks.empty())
		{
			kp = ks.top(); ks.pop();
			if (counts[kp.first] > 1)
			{
				found = true;
				break;
			}
		}

		if (!found) break;

		//置き換え
		//(n + 1)^2 - n^2 = 2n + 1
		score += (ll)p.second - (ll)kp.second + 2 * (ll)counts.size() + 1;

		if (score > maxScore) maxScore = score;
		counts[kp.first]--;
		counts[p.first]++;
	}

	cout << maxScore << endl;

	return 0;
}