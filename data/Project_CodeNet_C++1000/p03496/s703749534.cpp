#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

ll a[50];
ll N;
ll p,n;
vector<pair<ll,ll>> v;
vector<ll> pv,nv;
ll pl,nl;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];
    p = n = 0;
    pl = nl = -1;
    for(int i=0;i<N;i++){
        if(a[i] > 0){
            p += a[i];
            pv.push_back(i+1);
            pl = i+1;
        }
        if(a[i] < 0){
            n -= a[i];
            nv.push_back(i+1);
            if(nl == -1) nl = i+1;
        }
    }
    if(pl == -1 && nl == -1){
        cout << 0 << endl;
        return 0;
    }
    if(p > n){
        for(int i=1;i<pv.size();i++){
            v.push_back(make_pair(pv[i-1],pv[i]));
        }
        for(int i=0;i<nv.size();i++){
            v.push_back(make_pair(pl,nv[i]));
        }
        for(int i=1;i<N;i++) v.push_back(make_pair(i,i+1));
    }else{
        for(int i=nv.size()-1;i>=1;i--){
            v.push_back(make_pair(nv[i],nv[i-1]));
        }
        for(int i=0;i<pv.size();i++){
            v.push_back(make_pair(nl,pv[i]));
        }
        for(int i=N;i>1;i--) v.push_back(make_pair(i,i-1));
    }
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}