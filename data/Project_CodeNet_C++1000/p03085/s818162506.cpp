/*
    In the name of Allah

    MohammadErfan Gooneh

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define endl                        '\n'
#define all(a, n)                   for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define IOS                         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
int main() {
    IOS ;
    char b ;
    cin >> b;
    string a = "ATCG";
    //string b = "";
    if(a.find(b)%2)cout << a[a.find(b)-1] ;
    else cout << a[a.find(b)+1] ;



























return 0 ;
}
