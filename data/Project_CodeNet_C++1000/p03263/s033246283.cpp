#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<int>>a(h,vector<int>(w));
    vector<int>z1,z2,z3,z4;
    rep(i,h)rep(j,w){
        cin>>a[i][j];
    }
    int ans=0;
    rep(i,h)rep(j,w){
        if(a[i][j]%2!=0){
            if(i==h-1&&j==w-1)continue;
            if(j==w-1){
                a[i][j]--;
                a[i+1][j]++;
                z1.push_back(i);
                z2.push_back(j);
                z3.push_back(i+1);
                z4.push_back(j);
                ans++;
            }
            else{
                a[i][j]--;
                a[i][j+1]++;
                z1.push_back(i);
                z2.push_back(j);
                z3.push_back(i);
                z4.push_back(j+1);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    rep(i,z1.size()){
        cout<<z1[i]+1<<" "<<z2[i]+1<<" "<<z3[i]+1<<" "<<z4[i]+1<<endl;
    }
    return 0;
}