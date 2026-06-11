#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll gr=0,le=0;
    int ans=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            gr+=a[i]-b[i];
            v.push_back(b[i]-a[i]);
        }
        else if(a[i]<b[i]){
            le+=b[i]-a[i];
            ans++;
        }
    }
    if(ans==0){
        cout<<ans<<endl;
        return 0;
    }
    if(le>gr){
        cout<<-1<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    for(int p:v){
        le+=p;
        ans++;
        if(le<=0){
            cout<<ans<<endl;
            return 0;
        }
    }
}
