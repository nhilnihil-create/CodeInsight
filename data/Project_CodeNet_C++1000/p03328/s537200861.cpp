#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int ans=-a;
    for(int i=0;i<b-a;i++)ans += i;
    cout << ans << endl;
}