#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<int>pos(n+1);
    
    for(int i =1 ; i <=n ; i++ ) {
        int tmp;
        cin>>tmp;
        pos[tmp] = i;
    }
    
    int last = 0 , ans = 0 , cnt = 0;
    
    for(int i =1 ; i <= n ; i++ ) {
        
        if(pos[i] > last) {
            cnt++;
            ans = max(ans , cnt);
        }
        else cnt = 1;
        last = pos[i];
    }
    cout<<n-ans<<'\n';
    return 0;
    
    
}