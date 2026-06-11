#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = max(a,(max(b,c)))-min(a,min(b,c));
    cout << ans << endl;
   
    return 0;
}