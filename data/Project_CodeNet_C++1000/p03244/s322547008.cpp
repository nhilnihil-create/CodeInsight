#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int n;
int v[MAXX];

int main()
{
    _FastIO;

    cin >> n;
    int k = n / 2;
    vector<int> cnt(MAXX , 0);
    vector<int> cn(MAXX , 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i % 2)
            cnt[v[i]]++;
        else
            cn[v[i]]++;
    }
    vector<pair<int , int> > x;
    vector<pair<int , int> > y;
    for(int i = 1; i <= 100000; i++){
        if(cnt[i])
            x.push_back({cnt[i] , i});
        if(cn[i])
            y.push_back({cn[i] , i});
    }
    if(x.size() == 1){
        x.push_back({0 , 0});
    }
    if(y.size() == 1){
        y.push_back({0 , 100001});
    }
    sort(x.begin() , x.end());
    reverse(x.begin() , x.end());
    sort(y.begin() , y.end());
    reverse(y.begin() , y.end());
    int a = x[0].second;
    int b = y[0].second;
    int c = x[1].second;
    int d = y[1].second;
    int e = x[0].first;
    int f = y[0].first;
    int g = x[1].first;
    int h = y[1].first;
    if(a != b){
        int ans = k - e + k - f;
        cout << ans << endl;
        return 0;
    }
    int saleh = k - g + k - f;
    int revan = k - e + k - h;
    int ans = min(saleh , revan);
    cout << ans << endl;
    return 0;
}
