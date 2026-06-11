#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;



int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,3) cin >> a[i];
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int res = 1<<29;
    vector<int> bit(3);
    for(bit[0] = 1; bit[0] < (1<<n); ++bit[0]){
        for(bit[1] = 1; bit[1] < (1<<n); ++bit[1]){
            if(bit[0] & bit[1]) continue;
            for(bit[2] = 1; bit[2] < (1<<n); ++bit[2]){
                if(bit[0] & bit[2]) continue;
                if(bit[1] & bit[2]) continue;
                vector<int> sums(3, 0), nums(3, 0);
                rep(i,n){
                    rep(j,3){
                        if(bit[j] & (1<<i)){
                            sums[j] += l[i];
                            nums[j]++;
                        }
                    }
                }
                int score = 0;
                rep(i,3){
                    score += abs(sums[i] - a[i]);
                    score += (nums[i] - 1) * 10;
                }
                res = min(res, score);
            }
        }
    }
    cout << res << endl;
}