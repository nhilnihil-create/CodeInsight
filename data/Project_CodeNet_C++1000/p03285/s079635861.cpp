#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

    ll n;
    cin >> n;
    

    bool b[10000]={};
    for(ll i=0;i<=25;i++){
        for(ll j=0;j<=15;j++)b[4*i+7*j]=1;
    }
    if(b[n])cout << "Yes" << endl;
    else cout << "No" << endl;

}