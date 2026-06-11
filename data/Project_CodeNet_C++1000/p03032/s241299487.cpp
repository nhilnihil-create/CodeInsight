/// إِنَّ مَعَ الْعُسْرِ يُسْرًا
/// لَا أَبْرَحُ حَتَّىٰ أَبْلُغَ

#include <bits/stdc++.h>
#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld  double

#define HabdModeActive ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define PI acos(-1)
#define MAX 5000005
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);


int main() {
    HabdModeActive
    int n, e;
    cin >> n >> e;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll mx = 0;
    for (int i = 0; i <= e; i++) {
        ll num = e - i;
        for (int j = 0; j <= num && j <= n; j++) {
            ll f = num - j;
            priority_queue<ll> q;
            ll sum = 0;
            for (int k = n - 1; k >= 0 && k >= j && f > 0; k--, f--) {
                sum += arr[k];
                q.push(-arr[k]);
            }
            for (int k = 0; k < j && k < n; k++) {
                sum += arr[k];
                q.push(-arr[k]);
            }
            ll v = i;
            while (v--) {
                if (q.size() > 0 && q.top() > 0) {
                    sum += q.top();
                    q.pop();
                } else {
                    break;
                }
            }
            mx = max(sum, mx);
        }
    }
    cout<<mx<<endl;

    return 0;
}
/*
 * int n, e;
    cin >> n >> e;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int k = n - 1; k > i; k--) {
                for (int r = k; k < n; k++) {
                    priority_queue<ll> q;
                    ll sum = 0;
                    ll op = e;
                    for (int g = 0; g <= i && op > 0; g++, op--)
                        sum += arr[g], q.push(-arr[g]);
                    for (int g = 0; g <= j && op > 0; g++, op--) {
                        if (q.top() < 0) {
                            e--;
                            sum += q.top();
                            q.pop();
                        }
                    }

                    for (int g = n - 1; g >= k && op > 0; g--, op--)
                        sum += arr[g], q.push(-arr[g]);
                    for (int g = n-1; g >= r && op > 0; g--, op--) {
                        if (q.top() < 0) {
                            e--;
                            sum += q.top();
                            q.pop();
                        }
                    }
                    mx = max(sum, mx);
                }
            }
        }
    }
 */