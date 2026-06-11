#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>

typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e18;
const ll N = 2e3+1;
const ll mod = 1e9+7;


int main(){

    FASTIO;
    PRECISION; 

    ll ans = 0;

    int n,k;
    cin>>n>>k;

    vector<ll>arr(n);
    for(ll &x: arr){
        cin>>x;
    }

    for(int take = 0; take<=min(n,k); take++){
        for(int left=0;left<=take;left++){
            int right = take-left;
            
            vector<ll>store;
            for(int i=0;i<left;i++){
                store.push_back(arr[i]);
            }
            for(int j=0;j<right;j++){
                store.push_back(arr[n-1-j]);
            }

            int drop = k-take;
            sort(store.begin(),store.end(),greater<ll>());

            while(store.size() && store.back()<0 && drop){
                drop--;
                store.pop_back();
            }

            ll sum = 0;
            for(ll x: store){
                sum+=x;
            }

            ans = max(ans,sum);
            
        }

    }

    cout<<ans<<"\n";
}
