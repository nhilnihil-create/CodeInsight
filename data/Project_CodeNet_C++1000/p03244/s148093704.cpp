#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    map<int,int> mp_odd,mp_even;
    for(int i=0;i<n;i++){
        if(i%2==0){
            mp_odd[v[i]]++;
        }else{
            mp_even[v[i]]++;
        }
    }
    int mxo1=0,mxe1=0;
    int mxo1n,mxe1n;
    for(auto x:mp_odd){
        if(mxo1<x.second){
            mxo1=x.second;
            mxo1n=x.first;
        }
    }
    for(auto x:mp_even){
        if(x.first==mxo1n) continue;
        if(mxe1<x.second){
            mxe1=x.second;
            mxe1n=x.first;
        }
    }
    int mxo2=0,mxe2=0;
    int mxo2n,mxe2n;
    for(auto x:mp_even){
        if(mxo2<x.second){
            mxo2=x.second;
            mxo2n=x.first;
        }
    }
    for(auto x:mp_odd){
        if(x.first==mxo2n) continue;
        if(mxe2<x.second){
            mxe2=x.second;
            mxe2n=x.first;
        }
    }  
    int ans=min(n-mxe1-mxo1,n-mxe2-mxo2);
    cout << ans << endl;
}