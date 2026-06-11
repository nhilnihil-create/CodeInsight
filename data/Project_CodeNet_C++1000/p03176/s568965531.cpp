#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdlib>
#include <iomanip>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
const int M = 1e9+7;
const int N = 2*1e5;
using namespace std;
int n;
ll h[N];
ll beauty[N];
ll dp[N];
set<pair<ll,ll>> S;


int main(){
    AC
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>h[i];
    for(int i=0; i<n; i++)
        cin>>beauty[i];

    S.insert({0,0});
    for(int i=0; i<n; i++){
        auto optimal = prev(S.lower_bound({h[i],0}));
        dp[i] = beauty[i]+optimal->second;
        while(true){
            auto next = S.lower_bound({h[i],0});
            if(next!=S.end() && next->second<=dp[i])
                S.erase(next);
            else
                break;
        }
        S.insert({h[i], dp[i]});
    }
    cout<<*max_element(dp, dp+n)<<endl;

}