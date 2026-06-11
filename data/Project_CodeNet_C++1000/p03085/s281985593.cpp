#define _USE_MATH_DEFINES
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define vec     vector<int>
#define vecll   vector<ll>
#define vec2    vector<vector<int>>
#define vec2ll  vector<vector<ll>>
#define vpair   vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define mpair(v1, v2)    make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << var << "\n"
#define scn(var)         cin >> var;
#define pYes()           prt("Yes")
#define pNo()            prt("No")
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(var)      rep(i,var.size()){cout << var[i] << " ";} cout << "\n"

//----------------------------------------------------


int main(){
    char b;
    cin >> b;
    char x[4] = {'A', 'C', 'G', 'T'};
    char y[4] = {'T', 'G', 'C', 'A'};
    for(int i = 0; i < 4; i++){
        if(b == x[i]) cout << y[i] << endl;
    }

}