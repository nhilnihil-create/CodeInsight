#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    int n,m;
    cin >> n>> m;
    vector<ll> data(n);
    rep(i,0,n){
        cin >> data[i];
    }
    sort(data.begin(),data.end());
    vector<pair<ll,ll>> plus(m);
    rep(i,0,m){
        ll s,t;
        cin >> s>>t;
        plus[i].first = t;
        plus[i].second = s;
    }
    sort(plus.begin(),plus.end());
    reverse(plus.begin(),plus.end());
    //cout<<plus[0].first<<endl;
    ll k = 0;
    rep(i,0,m){
        rep(j,0,plus[i].second){
            if(data[k]<plus[i].first){
                data[k]=plus[i].first;
                k++;
            }else{
                break;
            }
        }
    }
    ll sum = 0;
    rep(i,0,n){
        sum += data[i];
    }
    cout<<sum<<endl;


    return 0;
}
