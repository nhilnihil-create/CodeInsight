#include <bits/stdc++.h>
#include <chrono>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9

typedef long long ll;

using namespace std;

const ll inf = 1e18;
const int mod = 1e9+7;
const int N = 1e5+5;
//int a[N];

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, ans;

    cin >> n;

    double arr[n], avg = 0, mini = INT_MAX;

    for (int i = 0; i < n; i++) {

        cin >> arr[i];
        avg += arr[i];
    }

    avg/=n;

    for (int i = 0; i < n; i++) {

        double diff = abs(arr[i]-avg);

        if (diff < mini) {

            mini = diff;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}


//long long vs int
//pow function (+0.5)
//read carefully: overflow, constraints, etc...
