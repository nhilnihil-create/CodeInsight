/*
author: Apoorv Singh
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <long long> vl;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
#define ll long long
#define pb push_back   
#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " " << (x) << endl;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second

ll modulo = 1e9 + 7;

template <class X>

void printarr(X arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

ll fpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n&1)
            ans = (ans * a);
        a = (a*a);
        n = n >> 1;
    }
    return ans;
}

const int M = 1e6 + 10;
int composite[M] = {0};

void sieve()
{
    FOR(i,2,M)
    {
        if (!composite[i])
        {
            for (int j = 2*i; j < M; j += i)
                composite[j] = max(composite[j], i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll n,p;
    cin >> n >> p;
    ll ans = 1;
    bool flag = false;
    FOR(i,2,int(1e6) + 1)
    {
    	if (!composite[i])
    	{
    		int count = 0; ll temp = p;
    		while (temp)
    		{
    			if (temp%i != 0)
    				break;
    			++count;
    			flag = true;
    			temp /= i;
    		}
    		ans *= fpow(i,count/n);
    	}
    }
    if (n == 1)
    	ans = p;
    cout << ans << endl;
    return 0;
}