#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int n , X;
int x[MAXX];
int a[MAXX];

int gcd(int a , int b){
    while(a && b){
        if(a > b)   a %= b;
        else    b %= a;
    }
    return a + b;
}

int main()
{
    _FastIO;

    cin >> n >> X;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        a[i] = abs(X - x[i]);
    }
    sort(a , a + n);
    int ans = a[0];
    for(int i = 1; i < n; i++){
        ans = gcd(ans , a[i]);
    }
    cout << ans << endl;
    return 0;
}
