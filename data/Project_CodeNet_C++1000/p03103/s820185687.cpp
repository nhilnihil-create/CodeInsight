#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(),vec.end());

    int now = 0;
    ll yen = 0;
    while(m>0){
        m--;
        yen += vec[now].first;
        if(--vec[now].second == 0) now++;
    }
    cout << yen << endl;


}