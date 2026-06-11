#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    pair<ll,ll> b[m];
    for(int i = 0; i < m; i++){
        int x , y;
        cin>>x>>y;
        b[i].first = y;
        b[i].second = x;
    }
    sort(a , a + n);
    sort(b , b + m);
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        if(b[j].second > 0){
            if(a[i] < b[j].first){
                a[i] = b[j].first;
                b[j].second--;
                i++;
            }else{
                j--;
            }
        }else{
            j--;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i];
    }
    cout<<ans;
}