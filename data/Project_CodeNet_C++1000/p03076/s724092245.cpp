/*
      author  : nishi5451
      created : 15.08.2020 00:18:18
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<int> a(5);
    rep(i,5) cin >> a[i];
    int sum = 0;
    int k = 10;
    rep(i,5){
        if(a[i]%10==0){
            sum += a[i];
        }
        else{
            k = min(k,a[i]%10);
            sum += (a[i]/10+1)*10;
        }
    }
    if(k!=10){
        sum -= (10-k);
    }
    cout << sum << endl;
    return 0;
}