#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = 0;
    for(int i = 0; i < 4; i++){
        int n; cin >> n;
        a[n]++;
    }
    if(a[1] == 1 && a[9] == 1 && a[7] == 1 && a[4] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}