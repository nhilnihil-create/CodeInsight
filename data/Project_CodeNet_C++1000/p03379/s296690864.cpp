#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> b(n);
    rep(i,n){
        cin >> x[i];
        b[i] = x[i];
    }
    int l = n/2;
    sort(b.begin(),b.end());
    int s = b[l-1];
    int t = b[l];
    if(s == t){
        rep(i,n)cout << s << endl;
    }
    else{
        rep(i,n){
            if(x[i] <= s)cout << t << endl;
            if(x[i] >= t)cout << s << endl;
        }
    }
}