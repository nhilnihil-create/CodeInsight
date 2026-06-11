#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<ll>
#define all(x) x.begin() , x.end()
#define mod(x,m) ((x%m + m )%m)

using namespace std;
void OJ();

#define ld long double
void solve(){
    int a , b , c;
    cin >> a >> b >> c;
    cout << ( a + b >= c ? "Yes" : "No");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //OJ();

    int t = 1;
    //cin >> t;
    while ( t-- ){
        solve();
    }
    return  0;
}

void OJ(){
#ifndef ONLINE_JUDGE
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\in.txt" , "r" , stdin  );
   // freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\out.txt", "w" , stdout );
#endif // ONLINE_JUDGE
}

