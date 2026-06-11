#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<ll>> cb(m,vector<ll>(2));
    for(int i=0;i<m;i++){
        cin>>cb[i][1]>>cb[i][0];
    }
    sort(a.begin(),a.end());
    sort(cb.begin(),cb.end(),greater<>());
    
    int index=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<cb[i][1];j++){
            if(cb[i][0]<=a[index]) break;
            if(index>=n) break;
            a[index]=cb[i][0];
            index++;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}