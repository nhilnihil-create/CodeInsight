#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<int> flgnum(41,0);
    vector<int> flgk(41,0);
    rp(j,41){
        flgk[j] += k%2ll;
        k/=2ll;
    }
    rp(i,n){
        ll a;
        cin >> a;
        rp(j,41){
            flgnum[j] += a%2ll;
            a/=2ll;
        }
    }
    /*for(auto i: flgnum){
        cout << i << " ";
    }
    cout << endl;*/
    ll sum=0ll;
    bool saidai=true;
    for(int i=40; i>=0; i--){
        if(saidai){
            if(flgk[i]==0){
                sum += (ll)flgnum[i]*(1ll<<i);
                //cout << sum << endl;
            }
            else{
                if(flgnum[i]<n-flgnum[i]){
                    sum += (ll)(n-flgnum[i])*(1ll<<i);
                }
                else{
                    saidai=false;
                    sum += (ll)flgnum[i]*(1ll<<i);
                }
            }
        }
        else{
            if(flgnum[i]<n-flgnum[i]){
                sum += (ll)(n-flgnum[i])*(ll)(1ll<<i);
            }
            else{
                sum += (ll)flgnum[i]*(ll)(1ll<<i);
            }
        }
    }
    cout << sum << endl;
    return 0;
}