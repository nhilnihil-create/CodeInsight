#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> x(m);
    ll total;
    for(int i=0; i<m; i++){
        cin >> x.at(i);
    }
    sort(x.begin(), x.end());
    total=x.at(m-1)-x.at(0);
    vector<int> dist(m-1);
    for(int i=0;i<m-1; i++){
        dist.at(i) = x.at(i+1) - x.at(i);
    }
    sort(dist.begin(), dist.end());
    reverse(dist.begin(), dist.end());
    for(int i=0; i<n-1; i++){
        if(i >= m-1) break;
        total -= dist.at(i);
    }
    cout << max((ll)0, total) << endl;
}