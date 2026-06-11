#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
int main() {
    int n,m;
    cin>>n>>m;
    long long x[n+1],y[n+1],z[n+1];
    long long ans=0;
    rep(i,n){
        cin>>x[i+1]>>y[i+1]>>z[i+1];
    }
    for (int i=0;i<(1<<3);i++){
        bitset<3> s(i);
        vector<long long> vec;
        for (int j=1;j<n+1;j++){
            long long ss=0;
            if (s.test(0)){
                ss+=x[j];
            }
            else{
                ss-=x[j];
            }
            if (s.test(1)){
                ss+=y[j];
            }
            else{
                ss-=y[j];
            }
            if (s.test(2)){
                ss+=z[j];
            }
            else{
                ss-=z[j];
            }
            vec.push_back(ss);
        }
        sort(all(vec));
        long long ans1=0;
        rep(j,m){
            ans1+=vec[j];
        }
        ans=max(ans,abs(ans1));
    }
    cout<<ans<<endl;


    return 0;
}