#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    ll n;
    cin>>n;
    ll a[n];
    bool pos = true;
    ll mini=1e9,ma=-1e9;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mini = min(mini,a[i]);
        ma = max(ma,a[i]);
        if(i && a[i] < a[i-1])pos=false;
    }
    if(pos){
        cout << 0 << endl;
        return 0;
    }
    vector<array<int,2>> v;
    if(abs(ma) > abs(mini)){
        int p = 0;
        for(int i=0;i<n;i++){
            if(ma == a[i])p=i;
        }
        for(int i=0;i<n;i++){
            // if(i==p)continue;
            v.push_back({p,i});
        }
        for(int i=0;i<n-1;i++){
            v.push_back({i,i+1});
        }
    }
    else{
        int p = 0;
        for(int i=0;i<n;i++){
            if(mini == a[i]) p=i;
        }
        for(int i=0;i<n;i++){
            // if(i==p)continue;
            v.push_back({p,i});
        }
        for(int i=n-1;i>=1;i--){
            v.push_back({i,i-1});
        }
    }
    cout << v.size() << endl;
    for(auto i:v){
        cout << i[0]+1 << " " << i[1]+1 << "\n";
    }

}