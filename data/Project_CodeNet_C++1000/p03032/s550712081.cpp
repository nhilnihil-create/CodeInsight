#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(int i=0;i<n;++i) cin>>v[i];


    long long ans=0;
    int m=min(n,k);
    for(int i=0;i<=m;++i){
        for(int j=0;i+j<=m;++j){
            vector<long long> t;
            long long cur=0;
            for(int l=0;l<i;++l){
                t.push_back(v[l]);
                cur+=v[l];
            }
            for(int l=0;l<j;++l){
                t.push_back(v[n-1-l]);
                cur+=v[n-1-l];
            }
            sort(t.begin(),t.end());
            int o=min<int>(t.size(),k-i-j);
            for(int l=0;l<o;++l){
                if(t[l]<0) cur-=t[l];
            }
            ans=max(ans,cur);
        }
    }

    cout<<ans<<endl;
}