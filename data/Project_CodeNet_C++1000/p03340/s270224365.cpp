#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll res = 0;
    int right = 0;
    int sum = 0;
    for(int left = 0; left < n; ++left){
        while(right < n && ((sum ^ a[right]) == (sum + a[right]))){
            sum += a[right];
            ++right;
        }
        res += right - left;
        if(left == right) ++right;
        else sum -= a[left];
    }
    cout << res << endl;
}