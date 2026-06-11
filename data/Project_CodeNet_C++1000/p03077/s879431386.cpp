#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    ll k, arr[6], mn = 1e17;
    cin >> k;
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    cout << (k/mn) + (k % mn != 0) + 4;
    return 0;
}
