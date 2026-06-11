#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    int n,k;cin >>n>>k;
    string s;cin >>s;
    vector<int>num;
    int now=1;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
        if(s[i]==(char)('0'+now)){
            cnt++;
        }
        else {
            num.push_back(cnt);
            now=1-now;
            cnt=1;
        }
    }
    if(cnt!=0)num.push_back(cnt);
    if(num.size()%2==0)num.push_back(0);
//    for(auto u:num){
//        cout <<u <<" ";
//    }
//    cout <<endl;
    vector<int>sum(num.size()+1,0);
    for (int i = 0; i < num.size(); ++i) {
        sum[i+1]=sum[i]+num[i];
    }
    int ans=1;
//    for(auto u:num){
//        cout <<u <<" ";
//    }
//    cout <<endl;
    for (int i = 0; i < num.size(); i+=2) {
        int left=i;
        int right=min(i+2*k+1,(int)num.size());
        int tmp=sum[right]-sum[left];
        ans=max(ans,tmp);
    }
    cout <<ans <<endl;
    return 0;
}

