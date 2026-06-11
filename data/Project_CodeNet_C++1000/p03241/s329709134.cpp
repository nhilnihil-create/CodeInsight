/**
*    author:  souzai32
*    created: 23.08.2020 18:33:00
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
#define mod 1000000007
using namespace std;


int main() {

    int n,m;
    cin >> n >> m;
    vector<int> p(0);
    
    for(int i=1; i*i<=m; i++){
        if(m%i==0){
            p.push_back(i);
            if(i!=m/i) p.push_back(m/i);
        }
    }
    sort(all(p));

    // rep(i,p.size()) cout << p[i] << endl;
    // cout << p.size() << endl;

    int left=0, right=p.size()-1,mid;
    int ans=1;
    rep(i,p.size()){
        if(p[i]>=n){
            ans=p[i];
            break;
        }
    }

    cout << m/ans << endl;

    return 0;
}