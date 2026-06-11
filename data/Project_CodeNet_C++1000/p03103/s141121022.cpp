#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pll =  pair<long long, long long >;
int main(){
    int n;
    cin >> n;
    long long m;
    cin >> m;
    vector<pll> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());

    long long res=0;
    for(int i=0; i<n && m>0; i++){
        res += vec[i].first * min(m,vec[i].second);
        m -= min(m, vec[i].second);
    }
    cout << res << endl;
}

