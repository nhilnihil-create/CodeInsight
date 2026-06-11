#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> P;
const int INF = 1e15;

signed main(){
    int n;
    cin >> n;
    vector<P> a(n), b(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a[i] = {l, i};
        b[i] = {r, i};
    } 
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    int ans = 0;
    int now = 0;
    vector<bool> used(n);
    int ita = 0, itb = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            while(ita < n && used[a[ita].second]) ita++;
        }else{
            while(itb < n && used[b[itb].second]) itb++;
        }
        if(ita >= n || itb >= n) break;
        if(i % 2 == 0){
            now += 2 * a[ita].first;
            used[a[ita].second] = true;
            ans = max(ans, now);
        }else{
            now -= 2 * b[itb].first;
            used[b[itb].second] = true;
            ans = max(ans, now);
        }
    }
    for(int i = 0; i < n; i++) used[i] = false;
    ita = 0, itb = 0;
    now = 0;
    for(int i = 0; i < n; i++){
        if(i % 2){
            while(ita < n && used[a[ita].second]) ita++;
        }else{
            while(itb < n && used[b[itb].second]) itb++;
        }
        if(ita >= n || itb >= n) break;
        if(i % 2){
            now += 2 * a[ita].first;
            used[a[ita].second] = true;
            ans = max(ans, now);
        }else{
            now -= 2 * b[itb].first;
            used[b[itb].second] = true;
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}