#include<bits/stdc++.h>
using namespace std;

int n,k,a;
vector<int> V;
int dp[100005];

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> a;
        V.push_back(a);
    }
    for (int i=1;i<=k;i++) {
        for (auto x : V) {
            if (x>i) {continue;}
            if (dp[i-x]==0) {dp[i]=1; break;}
        }
    }
    if (dp[k]==1) {cout << "First";}
    else {cout << "Second";}
}
