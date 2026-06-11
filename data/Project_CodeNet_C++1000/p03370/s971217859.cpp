//g++ -std=c++17 -Wall t.cpp -o test -g -O2
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define teto(a, b) (a+b-1)/(b)
 
const int MAX = 1000010;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-6;
const ld PI = acos(-1.0);

using namespace std;

// End - Template //

int main()
{sws;
    
    int m[1010];
    int n, x;
    cin >> n >> x;
    ll sum=0;
    int mm = INF;
    for(int i=0;i<n;i++){
        cin >> m[i];
        sum+=m[i];
        mm = min(mm, m[i]);
    }

    cout << n + (x-sum)/mm << endl;
    


    
    return 0;
}