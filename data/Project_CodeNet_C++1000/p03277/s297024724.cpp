#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//-------------------------↓↓↓↓↓↓------------------------

map<ll,ll> ac;
ll bit[1000000 + 10], n, a[100000 + 10];

ll summ(ll i){
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(ll i,ll x){
    while(i <= n){
        bit[i] += x;
        i += i & -i;
    }
}

bool check(ll res){
    ll sum[n + 2] = {}, b[n + 2] = {};
    ll cnt = 0, pos;

    for(int i = 0; i < n; i++){
        if(a[i] < res)sum[i + 1] = -1;
        else sum[i + 1] = 1;
    }
    sum[0] = n;

    for(int i = 0; i < n; i++){
        sum[i + 1] += sum[i];
    }
    for(int i = 0; i < n + 1; i++){
        b[i] = sum[i];
    }
    sort(b, b + n + 1);

    ll tmp = 1;
    for(int i = 0; i < n + 1; i++){
        ac[b[i]] = tmp;
        if(b[i] != b[i + 1])tmp++;
    }
    for(int i = 0; i < n + 1; i++){
        sum[i] = ac[sum[i]];
    }
    
    fill(bit, bit + 100000 + 10, 0LL);
    add(sum[0], 1LL);
    for(int i = 1; i < n + 1; i++){
        cnt += summ(sum[i]);
        add(sum[i], 1LL);
    }

    pos = n * (n + 1) / 4;
    if((n * (n + 1) / 2) % 2 == 1)pos++;
    
    if(cnt >= pos)return true;
    else return false;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    ll c[100000 + 10];
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i];
    }
    sort(c, c + n);

    ll le = 0, ri = n - 1, mid;
    while(ri - le > 1){
        mid = (le + ri) / 2;
        if(check(c[mid])){
            le = mid;
        }
        else{
            ri = mid;
        }
    }

    if(n == 1)cout << a[0] << "\n";
    else{
        for(ll i = min(ri + 10, n - 1); i >= max(le - 10, 0LL); i--){
            if(check(c[i])){
                cout << c[i] << "\n";
                return 0;
            }
        }
    }
    return 0;
}
