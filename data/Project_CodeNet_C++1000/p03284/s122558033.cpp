#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,i;
    cin >> n >> i;
    int ans = n%i;
    if(ans==0) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}