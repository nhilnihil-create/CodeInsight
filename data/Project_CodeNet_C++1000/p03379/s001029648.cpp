#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<ll>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    
    vector<ll>sorted=x;
    sort(sorted.begin(),sorted.end());
    ll mid=sorted[n/2],mid2=sorted[n/2-1];
    
    for(int i=0;i<n;i++){
        if(x[i]<mid)cout<<mid<<endl;
        else cout<<mid2<<endl;
    }
    
    return 0;
}