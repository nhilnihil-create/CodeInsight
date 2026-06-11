#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') ans ++;
    }
    if(ans > n-ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}