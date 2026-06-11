#include <bits/stdc++.h>
#define ll long long
using namespace std;
double EPS = 1e-9;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    ll c;
    scanf("%d %lld", &n, &c);
    pair<ll, int> sush[n];// dist, nut
    for(int i = 0;i < n;i++){
        scanf("%lld %d", &sush[i].first, &sush[i].second);
    }
    sort(sush, sush+n);
    ll sum_right[n];
    ll max_right[n];
    ll sum_left[n];
    ll max_left[n];
    sum_right[0] = sush[0].second - sush[0].first;
    max_right[0] = sum_right[0];
    for(int i = 1;i < n;i++){
        sum_right[i] = sush[i].second + sum_right[i-1] - (sush[i].first - sush[i-1].first);
        max_right[i] = max(sum_right[i], max_right[i-1]);
    }
    sum_left[n-1] = sush[n-1].second - (c - sush[n-1].first);
    max_left[n-1] = sum_left[n-1];

    for(int i = n-2;i >= 0;i--){
        sum_left[i] = sush[i].second + sum_left[i+1] + (sush[i].first - sush[i+1].first);
        max_left[i] = max(sum_left[i], max_left[i+1]);
    }
    ll res = max(0ll, sum_right[n-1]);
    for(int i = 0;i < n-1;i++){
        res = max(res, sum_right[i] + max(0ll, (max_left[i+1]) - sush[i].first));
    }
    res = max(res, sum_left[0]);
    for(int i = 0;i < n - 1;i++){
        res = max(res, sum_left[n - 1 - i] + max(0ll, (max_right[n-2-i]) - (c - sush[n - 1 - i].first)));
    }
    printf("%lld", res);


    return 0;
}

