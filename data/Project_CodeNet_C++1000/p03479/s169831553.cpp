#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x,y;
    cin >> x >> y;
    int ans=0;
    while(x<=y){
        x*=2;
        ans++;
    }
    cout << ans;
}