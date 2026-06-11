#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

ll gcd(ll x,ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    ll n,m;cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int i=0,j=0;
    ll g=gcd(n,m);
    while(i<n&&j<m){
        if(s[i]!=t[j]){
            cout<<-1<<endl;
            return 0;
        }
        i+=n/g;
        j+=m/g;
    }
    cout<<(n*m)/g<<endl;
    return 0;
}