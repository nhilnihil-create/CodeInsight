#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
 
int main(){
    ll N;
    cin >> N;
    vector<string> W(N);
    map<string, ll> v;
    cin >> W[0]; v[W[0]]++;
    rep(i, 1, N){
        cin >> W[i];
        if(W[i][0] != W[i-1][W[i-1].size()-1] || v.count(W[i]) > 0){
            cout << "No" << endl;
            return 0;
        }
        v[W[i]]++;
    }
    
    cout << "Yes" << endl;
    return 0;
}