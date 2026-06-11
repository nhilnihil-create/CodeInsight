#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    string s,t;
    cin>>s>>t;
    vector<int> ss(26);
    vector<int> tt(26);
    rep(i,s.size()){
        ss[s[i] - 'a']++;
        tt[t[i] - 'a']++;
    }
    sort(all(ss));
    sort(all(tt));
    rep(i,ss.size()){
        if(ss[i]!=tt[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}