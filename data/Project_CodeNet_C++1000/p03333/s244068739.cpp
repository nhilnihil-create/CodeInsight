#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    ll l[100002], r[100002];
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }
    sort(l, l + n, greater<ll>());
    sort(r, r + n);
    ll ans1 = 0;
    ll t = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(l[0] < 0){
                t = 0;
                if(r[0] > 0) break;
                ans1 = -r[0];
            }
            else{
                t = l[0];
                if(r[0] > l[0]) break;
                ans1 = l[0] * 2 - r[0];
            }
            t = -r[0];
        }
        else{
            if(l[i] < r[i - 1]) break;
            ans1 += l[i] - r[i - 1];
            t = l[i];
            if(l[i] < r[i]) break;
            ans1 += l[i] - r[i];
            t = -r[i];
        }
    }
    ans1 += abs(t);
    ll ans2 = 0;
    t = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(r[0] > 0){
                t = 0;
                if(l[0] < 0) break;
                ans2 = l[0];
            }
            else{
                t = -r[0];
                if(r[0] > l[0]) break;
                ans2 = l[0] - r[0] * 2;
            }
            t = l[0];
        }
        else{
            if(l[i - 1] < r[i]) break;
            ans2 += l[i - 1] - r[i];
            t = -r[i];
            if(l[i] < r[i]) break;
            ans2 += l[i] - r[i];
            t = l[i];
        }
    }
    ans2 += abs(t);
    cout << max(ans1, ans2) << endl;
}