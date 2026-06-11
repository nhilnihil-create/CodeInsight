#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;

int GCD(int a, int b){
    if(b==0) return a;
    else return (GCD(b,a%b));
}
int main(){
    int n;
    cin >> n;
    int ans = 2*n/GCD(2,n);
    cout << ans << endl;
}