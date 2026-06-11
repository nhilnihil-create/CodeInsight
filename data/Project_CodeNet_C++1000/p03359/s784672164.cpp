#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long int ll;
template<typename T> T changeMax(T& a, T b){if(a < b)a = b;return 0;}
const ll MOD = 1000000007;

int main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    if(a <= b){
        ans += a;
    }
    else{
        ans += a-1;
    }
    cout << ans << endl; 
    return 0;
}