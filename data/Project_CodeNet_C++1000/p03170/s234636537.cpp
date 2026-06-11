#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;

void test_case(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n), dp(k+1);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int pile=1; pile<=k; pile++){
        for(int i=0; i<n; i++){
            int stone=a[i];
            if(pile>=stone&&!dp[pile]){
                dp[pile]=(dp[pile-stone]^1);
            }
        }
    }
    cout<<(dp[k] ? "First" : "Second")<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }

    return 0;
}