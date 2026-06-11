#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a1(n);
    vector<int> a2(n);
    rep(i, n){
        cin >> a1[i];
    }
    rep(i, n){
        cin >> a2[i];
    }
    int maxi = 0;
    for (int i=0; i<n; i++){
        int sum  = 0;
        for (int j=0; j<=i; j++){
            sum += a1[j];
        }
        for (int k=i; k<n; k++){
            sum += a2[k];
        }
        maxi = max(maxi, sum);
    }
    out(maxi);
}