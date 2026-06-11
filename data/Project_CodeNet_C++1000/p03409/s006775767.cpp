#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
pair<ll,ll> a[105];
bool b[105];
pair<ll,ll> c[105];
bool d[105];

int main(){
    cin >> n;
    for(ll i=0;i<n;i++){
        ll p,q;
        cin >> p >> q;
        a[i]=make_pair(p,q);
    }
    for(ll i=0;i<n;i++){
        ll p,q;
        cin >> p >> q;
        c[i]=make_pair(p,q);
    }
    for(ll i=0;i<n;i++){
        b[i]=false;
        d[i]=false;
    }
    sort(a,a+n);
    sort(c,c+n);
    for(ll i=0;i<n;i++){
        ll memo=-1;
        for(ll j=0;j<n;j++){
            if(c[i].first>a[j].first&&c[i].second>a[j].second&&b[j]==false){
                if(memo==-1) memo=j;
                else{
                    if(a[j].second>a[memo].second) memo=j;
                }
            }
        }
        d[i]=true;
        b[memo]=true;
    }
    ll count=0;
    for(ll i=0;i<n;i++) if(b[i]) count++;
    cout << count << endl;
}
