#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b,c,d,e,k;
    cin >> a >> b >> c >> d >> e >> k;
    bool ans = (k<(e-a));
    if(ans) cout << ":(" << endl;
    else cout << "Yay!" << endl;
    return 0;
}