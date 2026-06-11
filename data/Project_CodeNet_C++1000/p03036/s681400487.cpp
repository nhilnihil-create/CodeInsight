#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int r,d,x;cin>>r>>d>>x;
    vector<int> ans(10);
    ans[0]=r*x-d;
    

    rep1(i,10){
        ans[i]=r*ans[i-1]-d;
    }
    rep0(i,10){
        cout<<ans[i]<<endl;
    }
}