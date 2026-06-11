#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int64_t ryuka(int n,vector<int64_t> &DP){
    if(DP.at(n) != -1){
        return DP.at(n);
    }else{
        int64_t ans;
        ans = ryuka(n-1,DP)+ryuka(n-2,DP);
        DP.at(n) = ans;
        return ans;
    }
}

int main(){
    int N;
    cin>>N;
    vector<int64_t> DP(N+1,-1);
    DP.at(0) = 2;
    DP.at(1) = 1;
    int64_t ans;
    ans = ryuka(N,DP);
    cout << ans << endl;
    return 0;
}