#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MAX 1005
#define MOD 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.14159265358979323846
#define Q ll _; cin >> _; while(_--)
#define endl "\n"
#define flush fflush(stdout);

int main(){

    fast

    ll i,n;
    cin >> n;
    ll a=0,b=0,c=0;
    for(i=1;i<=n;i++){
        ll a1,b1,c1;
        cin >> a1 >> b1 >> c1;
        ll a2 = a;
        ll b2 = b;
        ll c2 = c;
        a = a1 + max(b2,c2);
        b = b1 + max(a2,c2);
        c = c1 + max(a2,b2);
    }
    cout << max(a,max(b,c)) << endl;
}

//    cout << fixed << setprecision(12);
