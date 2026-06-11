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

    int x , y , z , k;
    cin>>x>>y>>z>>k;
    ll a[x], b[y], c[z];
    for(int i = 0; i < x; i++){
        cin>>a[i];
    }
    for(int i = 0; i < y; i++){
        cin>>b[i];
    }
    for(int i = 0; i < z; i++){
        cin>>c[i];
    }
    sort(a , a + x , greater<ll>());
    sort(b , b + y , greater<ll>());
    sort(c , c + z , greater<ll>());
    vector<ll> ans;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int l = 0; l < z; l++){
                if((i + 1)*(j + 1)*(l + 1) <= k){
                    ll sum = a[i] + b[j] + c[l];
                    ans.pb(sum);
                }else{
                    break;
                }
            }
        }
    }
    sort(all(ans) , greater<ll>());
    for(auto it : ans){
        if(k == 0){
            break;
        }
        cout<<it<<"\n";
        k--;
    }

    
}