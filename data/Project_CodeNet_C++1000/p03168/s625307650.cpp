#include <bits/stdc++.h>

#define mod 1000000007
using namespace std;

double dp[3001][3001];
vector<double> ar;

double func(int n, int heads){
    if (heads == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    if (heads > n) {
        return 0;
    }
    if (dp[n][heads] > -0.9) {
        return dp[n][heads];
    }
    return dp[n][heads] = ar[n]*func(n-1,heads-1) + (1-ar[n])*func(n-1,heads);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    double x;
    ar.push_back(0);
    for (size_t i = 0 ; i < n; i++) {
        cin>>x;
        ar.push_back(x);
    }
    std::cout << setprecision(10)<< func(n, (n+1)/2) << endl;
}
