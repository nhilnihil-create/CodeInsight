#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int gcd(int a , int b){
    while(a > 0 && b > 0){
        if(a > b)   a %= b;
        else    b %= a;
    }
    return a + b;
}

int a , b , k;

int main()
{
    _FastIO;
    cin >> a >> b >> k;
    int n = gcd(a , b);
    vector<int> v;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            if(i * i != n){
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    cout <<v[k - 1] << endl;
    return 0;
}
