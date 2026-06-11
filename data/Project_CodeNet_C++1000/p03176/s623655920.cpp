#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<vector<int> >adjlist;
vector<vector<int> >dp;

/*
4
3 1 4 2
10 20 30 40
*/

vector<int>h;
vector<int>b;
map<int,long long>m;
void solve(){
    int n;cin>>n;
    h.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){

        int x = h[i];
        long long val = b[i];
        auto itr = m.upper_bound(x);
        if(itr!=m.begin()){
            itr--;
            val += itr->second;
        }
        m[x] = val;
        itr = m.upper_bound(x);
        while(itr != m.end() && itr->second <=val){
            auto temp = itr;
            temp++;
            m.erase(itr);
            itr = temp;
        }
    }
    auto it = m.end();
    it--;
    long long ans  = it->second;
    cout << ans <<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    cout.precision(10);
    int t=1;//cin>>t;
    while(t--){

        solve();
    }
    return 0;
}
