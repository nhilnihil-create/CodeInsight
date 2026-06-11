#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned long long

#define f first
#define s second

#define endl '\n'
#define pii pair <ll, ll>

#define ios ios_base::sync_with_stdio(0), cin.tie()
#define pb push_back
#define mp make_pair

#define pi 3.14159265358979323846264
#define y1 abacaba
 
#define fn "abc"

using namespace std;

const int MXN = 1e6 + 30;
const int MAXN = 1e3 + 2;
const ll INF = 1e9 + 7;
const ll BINF = 1e16;
const int mod = 1e9 + 7;
const ld EPS = 1e-15;   
const ll dx[] = {0, 0, 1, -1};
const ll dy[] = {1, -1, 0, 0};

int n, w, h;

int main(){

    #ifdef DIAS
        freopen("input.txt", "r", stdin);
    #elif NAME 
    	freopen(fn".in", "r", stdin);
    	freopen(fn".out", "w", stdout);
    #endif       
    cin >> n;
    cin >> w >> h;
    cout << (n - w + 1) * (n - h + 1);
    return 0;
}