#include <bits/stdc++.h>
 
#define pb push_back
#define ll long long        
using namespace std;
 
void scan()
{
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
 
}
const int N = 1e6 + 500;
const int mod = 1e9 + 7;

int pref[N];
int main() 
{
    scan();    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
    	int l, r;
    	cin >> l >> r;
    	pref[l]++;
    	pref[r + 1]--;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
    	pref[i] += pref[i - 1];
    	if (pref[i] == m)
    	{
    		ans++;
    	}
    }
    cout << ans;
}     
//JUDGE_ID: 295965SY
//Tis I