#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int sum(ll n){
    int ret = 0;
    int digit = 0, num = 0;
    while(n > 0){
        num++;
        digit = n % 10;
        ret += digit;
        n /= 10;
    }
    return max(digit - 1 + (num - 1) * 9, ret);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    cout << sum(n) << endl; 
    return 0;
}
