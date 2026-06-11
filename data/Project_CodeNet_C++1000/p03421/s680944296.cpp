#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, a, b;

vector <int> solve(int n, int a, int b){
    vector <int> ans(n);
    int cur = 0;
    for(int i = 0 ; i < n ; i++){
        if(i % a == 0){
            cur = max(1, n - i / a * a - a + 1);
        }
        ans[i] = cur;
        cur++;
    }
    bool ok = (n + a - 1) / a == b;
    for(int i = a ; i < n ; i++){
        int d = (i + a - 1) / a;
        if(d + n - i == b){
            ok = 1;
            int cur = 1;
            for(int j = n - 1 ; j >= i ; j--){
                ans[j] = cur;
                cur++;
            }
            int l = i / a * a, r = min(n - 1, (i / a + 1) * a - 1);
            int g = r - i + 1;
            for(int j = l ; j < i ; j++){
                ans[j] += g;
            }
            break;
        }
    }
    if(ok == 0) return {};
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    if(a > n || b > n) finish(-1);
    vector <int> ans = solve(n, a, b);
    if(ans.size() == 0){
        ans = solve(n, b, a);
        for(auto &i : ans){
            i = n - i + 1;
        }
    }
    if(ans.size() == 0) finish(-1);
    for(auto &i : ans) cout << i << " ";
    cout << endl;
}
