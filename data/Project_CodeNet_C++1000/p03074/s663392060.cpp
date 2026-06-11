#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main() {
    ll N,K;
    cin >> N >>K;
    string S;
    cin >> S;
    vector<P> position0;
    for(int i=0;i<N;i++){
        int t= S[i]-'0';
        if(t==0){
            ll s = i;
            while(i<N-1 &&S[i+1]-'0' ==0){
                i++;
            }
            position0.push_back(P(s,i));
        }
    }
    if(position0.size()<=K){
        cout << N <<endl;
        return 0;
    }
    ll ans =0;
    for(int i=0;i<position0.size()-K+1;i++){
        ll temp =0;
        if(i == 0){
            temp = position0[i+K].first;
        }else if( i==position0.size()-K){
            temp = (N-1-position0[i-1].second);
        }
        else{
            temp = (position0[i+K].first - position0[i-1].second-1);
        }
        // cerr << "temp=" << temp<<", i="<<i <<endl;

        ans = max(ans,temp);

    }
    cout << ans << endl;

    return 0;
}