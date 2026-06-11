#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n;

int f(int n){
    int s = 0;
    for(int i = 1; i * i < n; i++){
        if(n % i == 0){
            s += 2;
        }
    }
    int k = int(sqrt(n));
    if(k * k == n)
        s++;
    return s;
}

int main()
{
    _FastIO;
    cin >> n;
    int s = 0;
    for(int i = 1; i <= n; i += 2){
        if(f(i) == 8)
            s++;
    }
    cout << s << endl;
    return 0;
}
