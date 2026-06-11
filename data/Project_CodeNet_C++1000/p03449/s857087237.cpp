#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    int n;
    cin >> n;
    vector<int> a1(n);
    vector<int> a2(n);
    rep(i,n) cin >> a1[i];
    rep(i,n) cin >> a2[i];
    int ans = 0;
    rep(i,n){
        int cnt = 0;
        for(int j = 0;j < n;j++){
            if (i == j){
                cnt += a1[i];
                cnt += a2[j];
            }
            else if (j < i){
                cnt += a1[j];
            }
            else{
                cnt += a2[j];
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}