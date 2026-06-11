#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    long long ans = 0;
    long long tempOne = 2;
    long long tempTwo = 1;
        for(int i=1; i<=n; i++){
            ans = tempOne+tempTwo;
            tempOne = tempTwo;
            tempTwo = ans;
        }
        cout << tempOne <<endl;
}
