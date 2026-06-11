#include <bits/stdc++.h>

using namespace std;

#define ll long long

//#define TEST

signed main(){
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0;i < n;++i)
        cin >> a[i];

    /* sum[i] = a[0]+a[1]+...+a[i-1] */
    ll* sum = new ll[n + 1];
    sum[0] = 0;
    for (int i = 1;i <= n;++i)
        sum[i] = sum[i - 1] + a[i - 1];

#ifdef TEST
    cout << "----------sum----------" << endl;
    for (int i = 0;i <= n;++i)
        cout << sum[i] << " ";
    cout << endl;
#endif

    ll ans = (ll)1e15;

    /* cut the sequence into two sequences like 
            a[0] a[1] ... a[i] | a[i+1] a[i+2] ... a[n-1]
       and get the sum of each sequence. */
    for (int i = 1;i < n - 2;++i){
#ifdef TEST
        cout << "---------i = " << i << "---------" << endl;
#endif
        /* calculate the sum of the left sequence. */
        ll sum_left = sum[i + 1];
        /* calculate the sum of the right sequence. */
        ll sum_right = sum[n] - sum_left;
        /* find the best place to cut the left sequence
           by using binary search.
                a[0] a[1] ... a[j] | a[j+1] ... a[i] */
        auto iter = lower_bound(sum,sum + i,sum_left / 2.0);
        ll p = *iter;
        ll q = sum_left - p;
        iter += 1;
        ll p_ = *iter;
        ll q_ = sum_left - p_;
        if (abs(p_ - q_) < abs(p - q)){
            p = p_;
            q = q_;
        }
        iter -= 2;
        p_ = *iter;
        q_ = sum_left - p_;
        if (abs(p_ - q_) < abs(p - q)){
            p = p_;
            q = q_;
        }
#ifdef TEST
        cout << "p : " << p << " (" << p << ")" << endl;
        cout << "q : " << q << " (" << p + q << ")" << endl;
#endif
        /* find the best place to cut the right sequence. */
        iter = lower_bound(sum,sum + n + 1,sum_left + sum_right / 2.0);
        ll r = *iter - sum_left;
        ll s = sum[n] - (p + q + r);
        iter += 1;
        ll r_ = *iter - sum_left;
        ll s_ = sum[n] - (p + q + r_);
        if (abs(r_ - s_) < abs(r - s)){
            r = r_;
            s = s_;
        }
        iter -= 2;
        r_ = *iter - sum_left;
        s_ = sum[n] - (p + q + r_);
        if (abs(r_ - s_) < abs(r - s)){
            r = r_;
            s = s_;
        }
#ifdef TEST
        cout << "r : " << r << " (" << p + q + r << ")" << endl;
        cout << "s : " << s << " (" << p + q + r + s<< ")" << endl;
#endif
        /* update ans. */
        ans = min(ans,max({p,q,r,s}) - min({p,q,r,s}));
    }

#ifdef TEST
    cout << "----------ans----------" << endl;
#endif
    cout << ans << endl;

    delete[] a,sum;
    return 0;
}