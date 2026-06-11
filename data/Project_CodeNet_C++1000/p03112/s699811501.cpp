#include <bits/stdc++.h>
using namespace std;

vector<long long> shrines, temples;
long long s, t, x, lshrine, rshrine, ltemple, rtemple, ans1, ans2, ans3, ans4, ans5, ans6, a, b, q;

long long solve(long long c, long long l, long long r) {
    while (l != r) {
        if (c > shrines[(l+r)/2]) {
            l = (l+r)/2+1;
        }
        else {
            r = (l+r)/2;
        }
    }
    if (shrines[l] > c) {
        l--;
    }
    if (l<1) return -10000000001;
    return shrines[l];
}

long long solve2(long long c, long long l, long long r) {
    while (l != r) {
        if (c > shrines[(l+r)/2]) {
            l = (l+r)/2+1;
        }
        else {
            r = (l+r)/2;
        }
    }
    if (shrines[l] < c) {
        l++;
    }
    if (l>a) return 20000000001;
    return shrines[l];
}

long long solve3(long long c, long long l, long long r) {
    while (l != r) {
        if (c > temples[(l+r)/2]) {
            l = (l+r)/2+1;
        }
        else {
            r = (l+r)/2;
        }
    }
    if (temples[l] > c) {
        l--;
    }
    if (l<1) return -10000000001;
    return temples[l];
}

long long solve4(long long c, long long l, long long r) {
    while (l != r) {
        if (c > temples[(l+r)/2]) {
            l = (l+r)/2+1;
        }
        else {
            r = (l+r)/2;
        }
    }
    if (temples[l] < c) {
        l++;
    }
    if (l>b) return 20000000001;
    return temples[l];
}

int main() {
    cin >> a >> b >> q;
    
    shrines.push_back(0);
    temples.push_back(0);
    
    for (long i=0; i<a; i++) {
        cin >> s;
        shrines.push_back(s);
    }
    
    for (long i=0; i<b; i++) {
        cin >> t;
        temples.push_back(t);
    }
    
    sort(shrines.begin(),shrines.end());
    sort(temples.begin(),temples.end());
    
    for (long i=0; i<q; i++) {
        cin >> x;
        lshrine = solve(x, 1, a);
        rshrine = solve2(x, 1, a);
        ltemple = solve3(x, 1, b);
        rtemple = solve4(x, 1, b);
        
        ans1 = x-min(lshrine,ltemple);
        ans2 = max(rshrine,rtemple)-x;
        ans3 = (x-lshrine)*2+rtemple-x;
        ans4 = (x-ltemple)*2+rshrine-x;
        ans5 = (rtemple-x)*2+x-lshrine;
        ans6 = (rshrine-x)*2+x-ltemple;
        
        ans2 = min(ans1, ans2);
        ans3 = min(ans2, ans3);
        ans4 = min(ans3, ans4);
        ans5 = min(ans4, ans5);
        ans6 = min(ans5, ans6);
        cout << ans6 << endl;
        //cout << lshrine << endl;
        //cout << rshrine << endl;
        //cout << ltemple << endl;
        //cout << rtemple << endl;
    }
    
    return 0;
}
