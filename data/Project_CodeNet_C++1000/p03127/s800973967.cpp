#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int x, int y){
    int a,b;
    a=max(x,y);
    b=min(x,y);
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;
    int ans;
    cin >> ans;
    for(int i=0; i<n-1; i++){
        int k;
        cin >> k;
        ans = gcd(ans, k);
    }
    cout << ans << endl;
}