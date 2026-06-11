#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v;
    vector<int> dp(k+1);
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<=k;i++){
        for(int stone : v){
            if(stone+i<=k){
                if(dp[i]==0) dp[i+stone] = 1;
            }
        }    
        
    }
    cout<<((dp[k])?"First":"Second");
}