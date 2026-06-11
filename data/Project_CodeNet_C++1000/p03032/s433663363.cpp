#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int x=min(n,k),mx=0;
    for(int i=0; i<=x; ++i){
        for(int j=0; j<=x-i; ++j){
            int sum=0;
            vector<int>ans;
            rep(l,i){
                ans.push_back(a[l]);
            }
            for(int l=n-1; l>n-1-j; --l){
                ans.push_back(a[l]);
            }
            sort(ans.begin(),ans.end());
            int y=k-i-j;
            rep(l,y){
                if(l>=ans.size())break;
                if(ans[l]<0)ans[l]=0;
            }
            rep(l,ans.size())sum+=ans[l];
            mx=max(mx,sum);
        }
    }
    cout<<mx<<endl;
}
