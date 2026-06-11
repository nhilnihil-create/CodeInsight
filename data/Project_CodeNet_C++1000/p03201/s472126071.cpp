#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;

int main() {
    int N; cin>>N;
    //vector<int> a(N);
    map<int,int,greater<>> mp;
    int a;
    for (int i = 0; i < N; ++i) {
        cin>>a;
        if(mp.find(a)==mp.end()){
            mp[a]=1;
        }else{
            mp[a]++;
        }
    }

    vector<int> beki;
    beki.push_back(1);
    for (int i = 0; i < 30; ++i) {
        beki.push_back(beki.back()<<1);
        //cout<<beki.back()<<endl;
    }
    int ans=0;
    for(auto yoso: mp){
        if(yoso.second==0) continue;
        int total=*lower_bound(beki.begin(),beki.end(),yoso.first);
        if(yoso.first==total){
            ans+=yoso.second/2;
            yoso.second-=(yoso.second/2)*2;
        }else{
            int aite=total-yoso.first;
            auto itr=mp.find(aite);
            if(itr!=mp.end()){
                int cnt=min(yoso.second,itr->second);
                ans+=cnt;
                yoso.second-=cnt;
                itr->second-=cnt;
            }
        }

    }

    cout<<ans<<endl;

    return 0;
}
