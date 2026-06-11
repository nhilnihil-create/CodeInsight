#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    vector<ll> T;
    T.push_back(2);
    rep(i,31) T.push_back(T.back()*2);
        
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(all(A));
    
    map<ll,int> Map;
    rep(i,N) Map[A[i]]++;
    
    ll ans = 0;
    for (int i = N-1; i >= 0; i--) {
        if(Map[A[i]] == 0) continue;
        Map[A[i]]--;
        ll t = *upper_bound(all(T), A[i]);
        ll a = t - A[i];
        ll b = *lower_bound(all(A),a);
        if(b!=a) continue;
        if(Map[b] > 0){
            ans++;
            Map[b]--;
        }
        

    }
    cout << ans << endl;
    
    
    
    return 0;
}

