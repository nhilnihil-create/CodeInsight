// In The Name Of Allah
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e10;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
const ll mod = 1e9 + 7;

 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const ll M = 500 + 10;
const ll N = 100 * 1000 + 10;

vector <pair <char, char>> tc;

int main()	
{
	faster();
	int n, q;
	string s;
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++)
	{
		char a, b;
		cin >> a >> b;
		tc.push_back({a, b});
	}
	int low = -1, high = n;
	for (int p = 0; p < 80; p++)
	{
		int mid = (low + high) / 2;
		int pos = mid;
		bool is_val = true, vulvul = false;
		for (int i = 0; i < q; i++)
		{
			char a = tc[i].first, b = tc[i].second;
			if(s[pos] == a && b == 'R')
			{
				pos++;
			}
			else if(s[pos] == a)
			{
				pos--;
			}
			if(pos == n)
			{
				is_val = false;
				break;
			}
			if(pos == -1)
			{
				vulvul = true;
				break;
			}
		}
		if(!is_val || !vulvul)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	int ans = low + 1;
	if(low == n)
		ans = 0;
	low = -1, high = n;
	for (int p = 0; p < 80; p++)
	{
		int mid = (low + high) / 2;
		int pos = mid;
		bool is_val = true, vulvul = false;
		for (int i = 0; i < q; i++)
		{
			char a = tc[i].first, b = tc[i].second;
			if(s[pos] == a && b == 'R')
			{
				pos++;
			}
			else if(s[pos] == a)
			{
				pos--;
			}
			if(pos == n)
			{
				vulvul = true;
				break;
			}
			if(pos == -1)
			{
				is_val = false;
				break;
			}
		}
		if(!is_val || !vulvul)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	cout << high - ans << endl;
}
