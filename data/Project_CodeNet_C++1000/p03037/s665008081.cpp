
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    int leftmax=1;
    int rightmin=n;
    for(int i=0; i<m; i++){
        int left, right;
        cin >> left >> right;
        leftmax = max(leftmax,left);
        rightmin = min(rightmin,right);
    }
    if(rightmin - leftmax <0){
        cout << 0 << endl;
        return 0;
    }
    cout << rightmin - leftmax + 1 << endl;
}