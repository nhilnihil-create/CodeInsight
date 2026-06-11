#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    ll m=0,a=0,r=0,c=0,h=0;
    vector<int> D(5);
    ll ans=0;
    vector<int> P = {0,0,0,0,0,0,1,1,1,2};
    vector<int> Q = {1,1,1,2,2,3,2,2,3,3};
    vector<int> R = {2,3,4,3,4,4,3,4,4,4};
    rep(i,n){
        string s;
        cin >> s;
        if(s[0] == 'M') m++;
        else if (s[0] == 'A')a++;
        else if (s[0] == 'R')r++;
        else if (s[0] == 'C')c++;
        else if (s[0] == 'H')h++;
    }
    D[0] = m; D[1] = a; D[2] = r; D[3] = c; D[4] = h;
    rep(i,10){
        ans += (ll)D[P[i]] * D[Q[i]] * D[R[i]];
    }
    cout << ans << endl;
    
}