#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,k;
    cin>>n>>k;
    deque<ll> v(n);
    rep(i,n) cin>>v[i];
    ll mx=0;
    for(ll i=0;i<=k;i++){
        for(ll l=0;l<=i;l++){
            ll sum=0;
            vector<ll> h;
            deque<ll> cv(n);
            cv=v;
            rep(j,l){
                if(cv.empty()) break;
                h.push_back(cv.front());
                sum+=cv.front();
                cv.pop_front();
            }
            rep(j,i-l){
                if(cv.empty()) break;
                h.push_back(cv.back());
                sum+=cv.back();
                cv.pop_back();
            }
            sort(all(h));
            rep(j,k-i){
                if(j>(ll)h.size()-1) break;
                else{
                    if(h[j]<0) sum-=h[j];
                    else break;
                }
            }
            mx=max(mx,sum);
        }

    }
    cout<<mx<<endl;
    return 0;
}