#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[1010];
int flag[1000010];
int n,k;
vector<LL>s;
bool cmp(LL a,LL b){
    return a>b;
}
int main(){
    cin>>n>>k;
    a[0]=0;
    for(int i=1;i<=n;i++){
        LL x;
        scanf("%lld",&x);
        a[i]=x+a[i-1];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            LL x=a[j]-a[i];
            s.push_back(x);
        }
    }
    sort(s.begin(),s.end(),cmp);
    LL x=s[0];
    int bit=0;
    //cout<<x<<endl;
    while(x){
        bit++;x>>=1;
    }
    //cout<<bit<<endl;
    LL ans=0;
    LL y=1LL<<bit;
    while(y){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(flag[i])continue;
            if(y&s[i])cnt++;
            //cout<<y<<" "<<(y&s[i])<<endl;
        }
        //cout<<cnt<<endl;
        if(cnt>=k){
            ans=ans|y;
            for(int i=0;i<s.size();i++){
                if(flag[i])continue;
                if((y&s[i])==0)flag[i]=1;
                    //cout<<i<<endl;
            }        
        }
        //cout<<y<<" "<<ans<<endl;
        y>>=1;
    }
    cout<<ans<<endl;
}