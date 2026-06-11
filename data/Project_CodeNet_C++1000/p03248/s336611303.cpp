#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    if(s.front() != '1' || s.back() != '0'){
        cout << -1 << endl;
        return 0;
    }
    s = '.' + s;
    for(i = 1;i < n;++i){
        if(s.at(i) != s.at(n-i)){
            cout << -1 << endl;
            return 0;
        }
    }
    s.at(n) = '1';
    queue<ll> que;
    for(i = 1;i <= n;++i){
        if(s.at(i) == '1') que.push(i);
    }
    for(i = 1;i < n;++i){
        if(i == que.front()) que.pop();
        cout << i << " " << que.front() << endl;
    }

    return 0;
}