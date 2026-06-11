#include<bits/stdc++.h>

using namespace std;
int main(){
    int h,w,a,b;
    cin >> a >> b;
    cin >> h >> w;
    int ans = (a-h)*(b-w);
    cout << ans << endl;
    return 0;
}