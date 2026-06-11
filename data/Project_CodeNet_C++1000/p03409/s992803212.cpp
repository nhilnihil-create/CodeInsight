#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second>b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> r(n),b(n);
    rep(i,n){
        cin >> r[i].first >> r[i].second;
    }
    sort(r.begin(),r.end());
    rep(i,n){
        cin >> b[i].first >> b[i].second;
    }
    sort(b.begin(),b.end());

    int ans=0;
    map<pair<int,int>,int> used;
    for(int i=0;i<n;i++){
        vector<pair<int,int>> cand;
        for(int j=0;j<n;j++){
            if(b[i].first>r[j].first&&b[i].second>r[j].second){
                if(used.find(r[j])==used.end()){
                    cand.push_back(r[j]);
                }
            }
        }
        sort(cand.begin(),cand.end(),cmp);
        //for(auto x:cand) cout << x.first << "  " << x.second << " ";
        //cout << endl;
        for(auto x:cand){
            if(used.find(x)==used.end()){
                ans++;
                used[x]++;
                break;
            }
        }
    }
    cout << ans << endl;
}