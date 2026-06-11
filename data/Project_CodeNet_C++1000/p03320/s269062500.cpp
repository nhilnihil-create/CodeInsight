#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int K;

ll digsum(ll a){
    ll sum = 0;
    while(a){
        sum += (a % 10);
        a /= 10;
    }
    return sum;
}

int main(){

    cin >> K;
    set<ll> cand;
    for(int i = 1; i <= 9; i++) {
        cand.insert(i);
    }
    for(int i = 1; i <= 9; i++){
        cand.insert(i * 10 + 9);
    }

    for(int i = 2; i <= 14; i++){
        ll base = 1;
        for(int j = 0; j < i; j++) base *= 10;
        ll suf = 0;
        for(int j = 0; j < i; j++) suf = suf * 10 + 9;
        for(int j = 1; j <= 500; j++){
            cand.insert(base * j + suf);
        }
    }

    vector<ll> cand2(cand.begin(), cand.end());
    sort(cand2.begin(), cand2.end());
    set<ll> ans;
    for(int i = 0; i < (int)cand2.size(); i++){
        ll a = cand2[i];
        bool ok = true;
        for(int j = i + 1; j < (int)cand2.size(); j++){
            ll b = cand2[j];
            if(a * digsum(b) > b * digsum(a)){
                ok = false;
            }
        }
        if(ok){
            ans.insert(a);
        }
    }

    auto it = ans.begin();
    for(int i = 0; i < K; i++){
        cout << *it << endl;
        it++;
    }

    return 0;
}
