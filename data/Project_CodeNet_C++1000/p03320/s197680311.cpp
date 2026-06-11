//https://betrue12.hateblo.jp/entry/2018/06/24/220417

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int k;
ll sum(ll num){
    ll res=0;
    while(num>0){
        res+=num%10;
        num/=10;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>k;
    ll last=1;
    vector<ll>ans;
    ans.push_back(1);
    ll diff=1;
    ll cur=k;
    while(--cur>0){
        ll num1=last+diff;
        ll num2=last+diff*10;
        ll next;
        if(num1*sum(num2)<=num2*sum(num1)){
            next=num1;
        }else
        {
            next=num2;
            diff*=10;
        }
        ans.push_back(next);
        last=next;        
    }
    rep(i,k)cout<<ans[i]<<endl;

    return 0;
}

