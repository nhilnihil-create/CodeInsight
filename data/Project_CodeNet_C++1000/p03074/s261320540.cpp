#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    int index=0,cnt=0;
    vector<int>zero,one;
    if(s[0]=='0')one.push_back(0);
    rep(i,n){
        cnt=1;
        while(i<n-1){
            if(s[i]!=s[i+1])break;
            cnt++;
            i++;
        }
        if(s[i]=='0')zero.push_back(cnt);
        else one.push_back(cnt);
    }
    if(s[n-1]=='0')one.push_back(0);

    if(zero.size()==0){
        cout<<s.size()<<endl;
        return 0;
    }
    if(zero.size()<=k){
        cout<<s.size()<<endl;
        return 0;
    }


    int ref=one[0];
    rep(i,k)ref+=(one[i+1]+zero[i]);

    int ans=ref;
    for(int i=k;i<(int)zero.size();i++){
        ref-=(one[i-k]+zero[i-k]);
        ref+=(one[i+1]+zero[i]);
        ans=max(ans,ref);
    }
    cout<<ans<<endl;

    return 0;
}