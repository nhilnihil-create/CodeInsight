/**
*    author:  souzai32
*    created: 15.08.2020 17:48:49
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    vector<bool> prime(int(1e5+1),false);
    prime.at(2)=true;
    for(int i=3; i<1e5; i+=2){
        prime.at(i)=true;
        for(int j=3; j*j<=i; j+=2){
            if(prime.at(j)){
                if(i%j==0){
                    prime.at(i)=false;
                    break;
                }
            }
        }
    }

    vector<int> p2017(int(1e5+1));
    for(int i=3; i<int(1e5+1); i++){
        p2017.at(i)=p2017.at(i-1);
        if(prime.at(i)&&prime.at((i+1)/2)) p2017.at(i)++;
    }

    int q,l,r;
    int ans;
    cin >> q;
    rep(i,q){
        cin >> l >> r;
        ans=p2017.at(r)-p2017.at(l-1);
        cout << ans << endl;
    }

    return 0;
}