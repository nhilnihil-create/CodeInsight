#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 2e6+1;
int n,k;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

void solve() {
    cin>>n>>k;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        mp[x]++;
    }
    vector<pair<int,int>> ar(mp.begin(), mp.end());
    sort(ar.begin(), ar.end(), cmp);
    int res=0;
    for(int i=0;ar.size()>=k && i<ar.size()-k;i++) {
        res += ar[i].second;
    }
    cout<<res<<endl;
}
 
int main() {
    solve();
    return 0;
}
