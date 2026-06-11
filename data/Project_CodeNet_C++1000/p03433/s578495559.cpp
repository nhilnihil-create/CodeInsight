#include<bits/stdc++.h>

using namespace std;
int main(){
    long n,a;
    cin >> n >> a;
    int ans=n%500;
    if(ans <= a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}