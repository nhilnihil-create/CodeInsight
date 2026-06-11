#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    cin>>n;
    vector<tuple<string, ll, int>> list;
    ll score;
    string city;
    rep(i,n){
        cin>>city>>score;
        list.emplace_back(city, score*(-1), i+1);
    }

    sort(begin(list), end(list));
    rep(i,n){
        // cout<<get<0>(list[i])<<","<<get<1>(list[i])*(-1)<<","<<get<2>(list[i])<<endl;
        cout<<get<2>(list[i])<<endl;
    }

}
