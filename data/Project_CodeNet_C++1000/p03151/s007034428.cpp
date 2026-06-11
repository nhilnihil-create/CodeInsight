#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

vector<int> v;

bool isOK(int index, int key) {
    if (v[index] >= key) return true;
    else return false;
}

int binary_search(int key) {
    int left = -1; 
    int right = (int)v.size(); 

    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    return right;
}

int main()
{
    int n;
    cin >> n;
    ll a_sum = 0, b_sum = 0;
    ll a[n],b[n];
    ll dif[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a_sum += a[i];
    }
    for(int i = 0; i < n; i++){
        cin >>  b[i];
        b_sum += b[i];
    }
    if(a_sum < b_sum){
        cout << -1 << endl;
    }else{
        vector<ll> plus;
        ll sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            dif[i] = a[i] - b[i];
            if(dif[i] < 0){
                sum -= dif[i];
                ans++;
            }else if(dif[i] > 0){
                plus.push_back(dif[i]);
            }
        }
        bool all = true;
        for(int i = 0; i < n; i++){
            if(dif[i] < 0) all = false;
        }
        if(all) {
            cout << 0 << endl;
            return 0;
        }
        int s = plus.size();
        sort(plus.begin(),plus.end());
        for(int i = s-1; i >= 0; i--){
            if(sum <= 0){
                break;
            }else{
                sum-=plus[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
}
