#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> drink(n);
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        pair<int, int> p=make_pair(a,b);
        drink.at(i) = p;
    }
    sort(drink.begin(), drink.end());
    int count=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        pair<int, int> p = drink.at(i);
        int a,b;
        a = p.first;
        b = p.second;
        int buy = min(m-count, b);
        count += buy;
        ans += (ll)a*buy;
        if(count == m) break;
    }
    cout << ans << endl;
}