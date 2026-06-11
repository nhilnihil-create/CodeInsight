#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int n, m, a[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; vector<pair<int,int>> vec;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        vec.pb({r,l});
    }
    sort(vec.begin(),vec.end());
    int cnt =0, st = 0;
    for(auto i : vec){
        if(i.s >= st){
            cnt++;
            st = i.f;
        }
    }
    cout << cnt << endl;
    return 0;
}
