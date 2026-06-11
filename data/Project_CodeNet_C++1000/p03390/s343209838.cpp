#include <bits/stdc++.h>

using namespace std;

#define int long long

int q;
int a, b;

bool solve(int v){
    int pos = v / 2;
    for(int i = max(1ll, pos - 10); i <= min(v, pos + 10); i++){
        int diff = v - i;
        int u = 1 + diff;
        int v = i;
        if(v <= b) v--;
        if(u >= a) u++;
        if(u * v >= a * b) return false;
    }
    return true;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        if(a > b) swap(a, b);
        int lo = 0, hi = 2000000000;
        while(lo != hi){
            int mi = (lo + hi + 1) >> 1;
            if(solve(mi)) lo = mi;
            else hi = mi - 1;
        }
        cout << lo-1 << endl;
    }
}
