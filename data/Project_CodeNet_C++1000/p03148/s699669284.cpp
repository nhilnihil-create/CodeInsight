#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<int,int> a, pair<int, int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int N, K; cin >> N >> K;
    vector<pair<int, int> > F_set, S_set;
    unordered_map<int,int> MP;
    for(int i = 0 ; i < N; i++){
        int t, d;
        cin >> t >> d;
        //ps[i] = {t, d};
        if(MP[t] == 0) MP[t] = d;
        else{
            if(MP[t] < d){
                S_set.push_back({t, MP[t]});
                MP[t] = d;
            }else{
                S_set.push_back({t,d});
            }
        }
    }
    for(auto itr = MP.begin(); itr != MP.end(); itr++ ){
        F_set.push_back({itr->first, itr->second});
    }
    sort(S_set.begin(), S_set.end(), comp);
    sort(F_set.begin(), F_set.end(), comp);

    ll ans = 0;
    ll pref = 0;
    ll pres = 0;
    if(K <= S_set.size()){
        for(int i = 0; i < K; i++){
            pres += S_set[i].second;
        }
        ans = pres;
        for(int i = 1; i <= K; i++){
            if(i - 1 >= F_set.size()) break;
            ll tmp = 0;
            tmp = (ll)i * (ll)i;
            pres -= S_set[K - i].second;
            pref += F_set[i-1].second;
            tmp += pres + pref;
            ans = max(ans, tmp);
        }
    }else{
        for(int i = 0; i < S_set.size(); i++){
            pres += S_set[i].second;
        }
        for(int i = 0; i < K - S_set.size(); i++){
            pref += F_set[i].second;
        }
        ans = pres + pref + pow((K - S_set.size()), 2);
        for(int i = K - S_set.size() + 1; i <= K; i++){
            if(i - 1 >= F_set.size()) break;
            ll tmp = 0;
            tmp = (ll)i * (ll)i;
            pres -= S_set[K - i].second;
            pref += F_set[i-1].second;
            tmp += pres + pref;
            ans = max(ans, tmp);
        }
    }
    /* 
    for(int i = 0; i <= K; i++){
        if(i > F_set.size()) break;

        ll tmp = 0;
        tmp += i * i;
        tmp += 
        pres += 
        for(int j = 0; j < K - i; j++){
            if(j >= S_set.size()) break;
            tmp += S_set[j].second;
        }
        for(int j = 0; j < i; j++){
            tmp += F_set[j].second;
        }
        ans = max(ans, tmp);
    } */
    cout << ans << endl;
}