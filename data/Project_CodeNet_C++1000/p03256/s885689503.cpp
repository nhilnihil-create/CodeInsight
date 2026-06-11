/*
t.me/ivanesipovvpered
*/
#pragma ARCENIY_KIRILLOV_POVELITEL_KROKODILOV
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;



main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector < vector <int> > g(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int a[n][2];
    for (int i = 0; i < n; i++)
        a[i][0] = a[i][1] = 0;
    for (int v = 0; v < n; v++){
        for (int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            a[to][s[v]-'A']++;
        }
    }
    stack<int> b;
    for (int i = 0; i < n; i++){
        if (!a[i][0] || !a[i][1]){
            b.push(i);
            a[i][0] = 0;
            a[i][1] = 0;
        }
    }
    int cnt = n;
    while (b.size()){
        int v = b.top();
        b.pop();
        cnt--;
        for (int i = 0; i < g[v].size(); i++){
                int to = g[v][i];
            if (a[to][s[v]-'A'] == 1 && a[to][(s[v]-'A')^1]){
                a[to][s[v]-'A']--;
                b.push(to);
                a[to][(s[v]-'A')^1] = 0;
            }
                a[to][s[v]-'A']--;
        }
    }
    if (cnt == 0){
        cout << "No";
    }else cout << "Yes";
}
