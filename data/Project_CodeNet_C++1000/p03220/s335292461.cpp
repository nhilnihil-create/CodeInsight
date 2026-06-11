#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//using ll = long long;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n,t,a;
    cin >> n >> t >> a;
    t *= 1000;
    a *= 1000;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    const int c = 6;
    int ans,dif = 100000000;
    rep(i,n){
        int temp = abs(a-(t - h[i]*c));
        if (temp < dif){
            ans = i+1;
            dif = temp;
        }
    }
    cout << ans;
}