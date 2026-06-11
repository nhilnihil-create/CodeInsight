#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P =pair<ll,ll>;
const ll INF =ll(1e18)+5;

int main() {
    ll N;
    cin >> N;
    vector<ll> v(N);
    map<ll,ll> oddMp;
    map<ll,ll> evenMp;
    for(int i=0;i<N;i++){
        cin >> v[i];
        if(i %2 ==0){
            oddMp[v[i]]++;
        }else{
            evenMp[v[i]]++;
        }
    }
    vector<P> oddP,evenP;
    for(auto itr = oddMp.begin();itr != oddMp.end();++itr){
        // cerr <<itr->first <<" "<< itr->second << endl;
        oddP.emplace_back(itr->second,itr->first);
    }
    for(auto itr = evenMp.begin();itr != evenMp.end();++itr){
        evenP.emplace_back(itr->second,itr->first);
    }
    sort(oddP.rbegin(),oddP.rend());
    sort(evenP.rbegin(),evenP.rend());

    // sort(oddMp.rbegin(),oddMp.rend());
    // sort(evenMp.rbegin(),evenMp.rend());
    ll ans = INF;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int oddNum=0;
            ll oddValue =0;
            int evenNum =0;
            ll evenValue =0;
            if(oddP.size()>i){
                oddNum = oddP[i].second;
                oddValue = oddP[i].first;
            }
            if(evenP.size()>j){
                evenNum = evenP[j].second;
                evenValue = evenP[j].first;
            }
            // cerr <<"evenNum=" << evenNum <<", oddNum=" << oddNum << endl;
            if(evenNum == oddNum){
                continue;
            }
            ans = min(ans,N-oddValue-evenValue);
        }
    }
    cout << ans << endl;

    return 0;
}