#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    bool isOK = false;
    int l = n / 4; 
    for(int i = l; i >= 0; --i){
        if((n - i * 4) % 7 == 0) isOK = true;
    }
    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;
}