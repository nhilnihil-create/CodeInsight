#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<string>
#include<stdio.h>
#include<cmath>
#include<map>
#include<bitset>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long


int main(){
    int n; cin >> n;
    vector<lint> a;
    rep(i, n){
        lint x; cin >> x;
        a.push_back(x);
    }

    lint count = 0;
    lint sum = 0;
    lint xr = 0;
    int r = 0;
    for(int l = 0; l < n; l++){
        while(r < n){
            if (sum + a[r] == (xr ^ a[r])){
                sum += a[r];
                xr ^= a[r];
                r++;
            }
            else{
                break;
            }
        }
        count += r - l;
        sum = sum - a[l];
        xr = xr ^ a[l];
        if(r == l) r++;
    }
    cout << count << endl;

}