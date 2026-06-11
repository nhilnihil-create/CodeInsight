#include<bits/stdc++.h>
#define ll long long
#define P pair<ll ,ll>
using namespace std;

int main(){
    ll n ,m;
    cin >> n >> m;
    priority_queue<ll ,vector<ll> ,greater<ll>> a;
    for(int i=0;i<n;i++) {
        ll x; cin >> x;
        a.push(x);
    }

    priority_queue<P> que;
    for(int i=0;i<m;i++){
        ll b ,c;
        cin >> b >> c;
        que.push(P {c ,b});
    }

    bool conti = true;
    while(conti && !que.empty()){
        P p = que.top();que.pop();
        for(int i=0;i<p.second;i++){
            ll t = a.top();a.pop();
            if(t >= p.first){
                if(i == 0) conti = false;
                a.push(t);
                break;
            }else{
                t = p.first;
                a.push(t);
            }
        }
    }

    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += a.top();
        a.pop();
    }

    cout << sum << endl;

}
