
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int n; cin >> n;
    vector<long long int> l(n+1);
    l[0] = 2;
    l[1] = 1;
    if(n==1) cout << 1 << endl;
    else{
        for(int i=2; i<=n; i++){
            l[i] = l[i-1] + l[i-2]; 
        }
        cout << l[n] << endl;
    }

}