#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> A;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >>b;
        --a;--b;
        A.emplace_back(a,b);
    }
    sort(A.rbegin(),A.rend());
    set<ll> s;
    for(auto P:A){
        auto itr =s.lower_bound(P.first);
        if(itr == s.end()){
            s.insert(P.first);
        }else if(*itr>=P.second){
            s.insert(P.first);
        }
    }
    cout << s.size() << endl;
    return 0;
}