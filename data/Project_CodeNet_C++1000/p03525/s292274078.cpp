#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> cnt(15,0);
    cnt[0]++;
    for(auto it:a)cnt[it]++;
    for(auto it:cnt){
        if(it>=3){
            cout<<0<<endl;
            return 0;
        }
    }
    int res=0;
    for(int bit=0;bit<(1<<12);bit++){
        vector<int> now(24,0);
        for(int i=0;i<=12;i++){
            if(i==0||i==12){
                if(cnt[i]>1){
                    cout<<0<<endl;
                    return 0;
                }else if(cnt[i]==1){
                    now[i]=1;
                }
            }else{
                if(cnt[i]==2){
                    now[i]=1;
                    now[24-i]=1;
                }else if(cnt[i]){
                    if(bit&(1<<i))now[i]=1;
                    else now[24-i]=1;
                }
            }
        }
        vector<int> v;
        for(int i=0;i<24;i++){
            if(now[i])v.push_back(i);
        }
        if(v[0]==0)v.push_back(24);
        int temp=100000000;
        for(auto p:v){
            for(auto q:v){
                if(p==q)continue;
                temp=min(temp,abs(p-q));
            }
        }
        res=max(temp,res);
    }
    cout<<res<<endl;
}