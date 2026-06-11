#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll h,w,n;
    cin >> h >> w >> n;

    vector<pair<ll,ll>> p;
    for(int i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;
        p.push_back(make_pair(b,a));
    }
    for(ll i = 1; i <= w; i++){
        p.push_back(make_pair(i,h+1));
    }

    sort(p.begin(),p.end());

    ll ans = INF;
    ll next = 1;

    for(ll i = 1; i <= w; i++){
        if(next > h){
            break;
        }
        auto itr = lower_bound(p.begin(),p.end(),make_pair(i,next));
        if((*itr).second == next){
            bool flag = true;
            while(flag){
                if(itr != p.end() && (*itr).second == next){
                    next++;
                    itr++;
                }else{
                    flag = false;
                }
            }
        }
        if(next > h){
            break;
        }
        auto itr2 = upper_bound(p.begin(),p.end(),make_pair(i,next));
        ans = min(ans,(*itr2).second-1);
        next++;
    }

    cout << ans << endl;
    
    return 0;
}