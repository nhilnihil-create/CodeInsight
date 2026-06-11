#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#define MOD 1000000007
#define REP(i,st,num)for(int i=(st);i<(num);++i)
#define ll long long
using namespace std;

int N,A[200001];
ll S[2000002],ans=LLONG_MAX;

int can(ll high) {
    vector<ll> nums;
    int idx=0,before=0;
    REP(i,1,N+2){
        if(S[i] - S[before] > high) {
            if(i-1==before){
                nums.push_back(S[i]-S[before]);
                before=i;
            }else{
                nums.push_back(S[i-1]-S[before]);
                before=i-1;
            }

        }
    }
    if(before!=N){
        nums.push_back(S[N+1]-S[before]);
    }
    // cout<<high<<endl;
    // REP(i,0,nums.size()){
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"idx = " << idx << endl;
    if (nums.size() < 4)return -1;
    else if (nums.size() > 4) return 1;
    ll mi=LLONG_MAX,ma=-1;

    REP(i,0,4){
        mi=min(mi,nums[i]);
        ma=max(ma,nums[i]);
    }
    // cout<<endl;
    // cout<<"ans = " << (ma-mi)<<endl;
    ans = min(ans, (ma-mi));
    return 0;
}

ll maxValue(ll a, ll b, ll c, ll d){
    ll ans=-1;
    ans=max(ans,a);
    ans=max(ans,b);
    ans=max(ans,c);
    ans=max(ans,d);
    return ans;
}
ll minValue(ll a, ll b, ll c, ll d){
    ll ans=LLONG_MAX;
    ans=min(ans,a);
    ans=min(ans,b);
    ans=min(ans,c);
    ans=min(ans,d);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin>>N;
    S[0]=0;
    REP(i,0,N){
        cin>>A[i];
        S[i+1] = S[i]+A[i];
    }
    int left=1,right=3;
    ll ans=LLONG_MAX,b,c,d,e;
    REP(i,3,N){
        ll lSum=S[i-1]-S[0];
        ll rSum=S[N]-S[i-1];
        // cout<<lSum<<" "<<rSum<<endl;
        while (lSum/2>S[left+1]&&left<i-1)left++;
        while (rSum/2>S[right+1]-S[i-1]&&right<N)right++;
        b=S[left];
        c=lSum-S[left];
        d=S[right]-S[i-1];
        e=S[N]-S[right];
        if(abs(c-b)>abs((lSum-S[left+1])-S[left+1])){
            left++;
            b=S[left];
            c=lSum-S[left];
        }
        if(abs(e-d)>abs((S[N]-S[right+1])-(S[right+1]-S[i-1]))){
            right++;
            d=S[right]-S[i-1];
            e=S[N]-S[right];
        }
        // cout<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
        ans=min(ans,maxValue(b,c,d,e)-minValue(b,c,d,e));
        // cout<<"ans = " <<ans<<endl;
    }
    cout<<ans;
    return 0;
}
//10
//10 71 84 33 6 47 23 25 52 64
//