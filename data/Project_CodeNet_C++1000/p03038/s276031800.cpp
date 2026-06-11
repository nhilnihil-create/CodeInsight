#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,i,j;
    long long ans = 0;
    cin >> n >> m;
    vector<long long> a(n);
    vector<pair<long long ,int>> c(m);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        cin >> c[i].second >> c[i].first;
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end(),greater<pair<long long ,int>>());

    j = 0;
    for(i = 0;i < n;i++){
        if(a[i] < c[j].first){
            a[i] = c[j].first;
            c[j].second--;
            if(j < m && c[j].second == 0)j++;
        }
    }
    for(int i= 0;i < n;i++){
        ans += a[i];
    }
    cout << ans << endl;
}
