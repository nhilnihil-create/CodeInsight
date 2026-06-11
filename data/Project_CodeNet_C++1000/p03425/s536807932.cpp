#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> m(5);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s[0]=='M') m[0]++;
        if(s[0]=='A') m[1]++;
        if(s[0]=='R') m[2]++;
        if(s[0]=='C') m[3]++;
        if(s[0]=='H') m[4]++;
    }
    ll ans=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++) ans+=m[i]*m[j]*m[k];
        }
    }
    cout<<ans<<endl;
}