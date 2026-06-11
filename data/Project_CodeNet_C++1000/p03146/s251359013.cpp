#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    vector <int> a(1000001,0);
    ll s;
    cin >> s;
    rep(i,1000001){
        if(a[s]==1){
            cout << i+1 << endl;
            break;
        }
        else{
            a[s]=1;
            if(s%2==1){
                s=3*s+1;
            }
            else{
                
                    s/=2;
                
            }
        }
    }
    

    return 0;
}