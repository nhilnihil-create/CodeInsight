#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=100000000000000000;

ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

string bigger(string a,string b){
    string aa,bb;
    if(a.size()>b.size()){
        return a;
    }else if(b.size()>a.size()){
        return b;
    }
    for(ll i=0;i<a.size();i++){
        aa=a[i];
        bb=b[i];
        if(stoi(aa)>stoi(bb)){
            return a;
        }else if(stoi(aa)<stoi(bb)) {
            return b;
        }
    }
    return a;
}

int main(){
    ll n,m;cin>>n>>m;
    ll aa[m];
    vector<ll> a;
    ll num[10]={0,2,5,5,4,5,6,3,7,6};
    ll b[8]={0,0,0,0,0,0,0,0};
    for(ll i=0;i<m;i++){
        cin>>aa[i];
        b[num[aa[i]]]=max(b[num[aa[i]]],aa[i]);
    }
    m=0;
    for(ll i=0;i<8;i++){
        if(b[i]!=0){
            m++;
            a.push_back(b[i]);
        }
    }
    sort(a.begin(),a.end(),greater<ll>());
    string dp[n+1][m];
    dp[0][0]="";
    for(ll i=1;i<=n;i++){
        if(i%num[a[0]]==0){
            dp[i][0]=dp[i-num[a[0]]][0]+to_string(a[0]);
        }else{
            dp[i][0]="";
        }
    }
    for(ll j=1;j<m;j++){
        for(ll i=0;i<=n;i++){
            if(i-num[a[j]]<0){
                dp[i][j]=dp[i][j-1];
            }else if(i==num[a[j]]){
                dp[i][j]=bigger(dp[i][j-1],(dp[i-num[a[j]]][j]+to_string(a[j])));
            }else if(dp[i][j-1]=="" && dp[i-num[a[j]]][j]==""){
                dp[i][j]="";
            }else if(dp[i][j-1]==""){
                dp[i][j]=dp[i-num[a[j]]][j]+to_string(a[j]);
            }else{
                dp[i][j]=bigger(dp[i][j-1],(dp[i-num[a[j]]][j]+to_string(a[j])));
            }
        }
    }
    cout<<dp[n][m-1]<<endl;
    return 0;
}

