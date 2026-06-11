#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    ll n;  cin >> n;
    ll L[87];

    rep(i,87){
        if(i==0)    L[i] = 2;
        else if(i==1)    L[i] = 1;
        else    L[i] = L[i-1]+L[i-2];
    }

    cout << L[n] << endl;

    return 0;
}