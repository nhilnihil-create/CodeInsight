#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

using tpl = tuple<char, int>;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

ll N, A, B;

int main(){


    cin >> N >> A >> B;


    if(A + B - 1 > N){
        cout << -1 << endl;
        return 0;
    }

    deque<ll> dq;
    for(ll i = 0; i < A; i++)
        dq.push_back(i * B + B - 1);
    for(ll i = 0; i < B - 1; i++)
        dq.push_back(A * B - 2 - i);


    vector<ll> seq;
    for(ll i = 0; i < A; i++){
        for(ll j = B - 1; j >= 0; j--){
            ll left = N - (ll)seq.size();
            if(left == (ll)dq.size()){
                for(ll d : dq){
                    seq.push_back(d);
                }
                break;
            }
            else{
                const ll a = i * B + j;
                seq.push_back(a);
                if(a == dq[0]){
                    dq.pop_front();
                }
            }
            if((ll)seq.size() == N) break;
        }
        if((ll)seq.size() == N) break;
    }

    if((int)seq.size() < N) {
        cout<< -1 << endl;
        return 0;
    }
    
    vector<pll> v;
    for(ll i = 0; i < (ll)seq.size(); i++){
        v.push_back(make_pair(seq[i], i));
    }

    sort(v.begin(), v.end());

    vector<ll> anss(N);

    for(ll i = 0; i < (ll)v.size(); i++){
        anss[v[i].second] = i + 1;
    }
    for(ll a : anss){
        cout << a << " ";
    }
    cout << endl;
    
    

    return 0;
}
