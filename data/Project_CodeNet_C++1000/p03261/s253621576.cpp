#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N; cin>>N;
    map<string,ll> mp;
    vector<string> w(N);
    for (ll i = 0; i < N; i++){
        cin>>w[i];
        mp[w[i]]++;
    }
    for (ll i = 1; i < N; i++){
        if(mp[w[i]]>=2){ //同じ単語が2回以上出ているか判定
            cout<<"No"<<endl;
            return 0;
        }
        if(w[i-1][w[i-1].size()-1]==w[i][0]){ //しりとり
                continue;
        }else{
                cout<<"No"<<endl;
                return 0;
        }
    }
    cout<<"Yes"<<endl;
    
}
