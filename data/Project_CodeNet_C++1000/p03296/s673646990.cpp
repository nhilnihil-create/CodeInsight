#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(x>y)swap(x,y);
    for(int i=x; i >= 1; i--){
        if(i == 1)return 1;
        else if( x % i  == 0 && y % i == 0)return i;
        //最大公約数、lcm = x*y/gcd 僕のVSCではgcd関数が使えませんでした(泣)だれか教えてください。
    }
}
typedef long long ll;

int main(){ 
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i] == a[i+1]){
            a[i+1] = 0;
            ans++;
        }
    }
    cout << ans << endl;
}