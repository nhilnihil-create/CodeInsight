#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    cin>>n;
    vector<int>t(13);
    t[0]=1;
    rep(i,n){
        int d; cin>>d;
        t[d]++;
    }
    rep(i,13){
        if(i==0||i==12){
            if(t[i]>=2){cout<<0<<endl; return 0;}
        }
        else{
            if(t[i]>=3){cout<<0<<endl; return 0;}
        }
    }
    vector<bool>solo(13,false);
    for(int i=1; i<=11; ++i){
        if(t[i]==1)solo[i]=true;
    }
    vector<int>x;
    rep(i,13){
        if(!solo[i]&&t[i]!=0){
            if(i==0||i==12){
                x.push_back(i);
            }
            else{
                x.push_back(i);
                x.push_back(24-i);
            }
        }
    }
    int ans=0;
    rep(bit,1<<13){
        vector<int>y=x;
        rep(i,13){
            if(!solo[i])continue;
            if(bit&(1<<i))y.push_back(i);
            else y.push_back(24-i);
        }
        sort(y.begin(),y.end());
        int cnt=1e9,m=y.size();
        rep(i,m-1){
            cnt=min(cnt,abs(y[i]-y[i+1]));
        }
        cnt=min(cnt,abs(y[0]+24-y[m-1]));
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}