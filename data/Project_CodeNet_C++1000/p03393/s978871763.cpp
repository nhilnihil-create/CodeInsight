/*
author : seryu
title : AGC022A_"Diverse Word"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,from,n) for(int i = from; i < n; i++)
#define mreps(i,from,n) for(int i = from; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
typedef long long ll;
typedef pair<ll, ll> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;

void solve()
{	
    string s;
    cin >> s;
    string last_word = "";
    rep(i, 26)last_word.push_back('z'-i);
    if(s == last_word)
    {
        cout << -1 << endl;
        return;
    }
    reverse(all(last_word));
    if(s == last_word)
    {
        cout << last_word.substr(0,24)+"z" << endl;
        return;        
    }
    int n = sz(s);
    if(n < 26)
    {
        bool a[26] = {false};
        rep(i, n)
        {
            a[s[i]-'a'] = true;
        }
        string ans = s;
        rep(i, 26)
        {
            if(!a[i])
            {
                ans.push_back('a'+i);
                cout << ans << endl;
                return;
            }
        }
    }
    else
    {
        int k = n-1;
        while (true)
        {
            if(s[k-1] < s[k])break;
            k--;
        }
        bool a[26] = {false};
        rep(i, k)a[s[i]-'a'] = true;
        k--;
        mrep(i, s[k]-'a'+1,26)
        {
            if(!a[i])
            {
                string ans = s.substr(0, k);
                ans.push_back('a'+i);
                cout << ans << endl;
                return;
            }    
        }
    }
    
	return;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}

