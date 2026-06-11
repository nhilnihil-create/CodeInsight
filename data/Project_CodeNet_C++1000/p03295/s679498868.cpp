#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i].second >> a[i].first;//first = b, second = a
    }

    sort(a.begin(), a.end());
    int x = a[0].first-1;
    int ans = 1;
    for(int i = 0; i < m; i++){
        if(x + 1 <= a[i].second){
            ans++;
            x = a[i].first-1;
        }
    }
    cout << ans << endl;
}