#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int q;
    scanf("%d", &q);
    while(q--){
        int k;
        scanf("%d", &k);
        deque<int> d;
        deque<int> m;
        lint sum = 0;
        lint ans = 0;
        rep(i, n){
            while(!d.empty() && i-d[0] >= k){
                d.pop_front();
                sum -= (lint)m.size();
                while(!d.empty() && !m.empty() && m[0] < d[0]) m.pop_front();
            }
            if(s[i] == 'D') d.push_back(i);
            if(s[i] == 'M'){
                if(d.empty()) continue;
                m.push_back(i);
                sum += (lint)d.size();
            }
            if(s[i] == 'C') ans += sum;
        }
        printf("%lld\n", ans);
    }
}