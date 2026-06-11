#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long
 
const int N = 18;
 
int n;
vector <int> a, ans[1 << 18];
 
void add(vector <int> &c, int x){
    c.push_back(x);
    sort(c.rbegin(), c.rend());
    while(c.size() > 2) c.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(1 << n);
    for(auto &i : a) cin >> i;
    for(int i = 0 ; i < (1 << n) ; i++){
        add(ans[i], a[i]);
    }
    for(int j = 0 ; j < n ; j++){
        for(int i = 1 ; i < (1 << n) ; i++){
            if((i >> j) & 1){
                for(auto &k : ans[i ^ (1 << j)]){
                    add(ans[i], k);
                }
            }
        }
    }
    int res = 0;
    for(int i = 1 ; i < (1 << n) ; i++){
        res = max(res, ans[i][0] + ans[i][1]);
        cout << res << "\n";
    }
}
