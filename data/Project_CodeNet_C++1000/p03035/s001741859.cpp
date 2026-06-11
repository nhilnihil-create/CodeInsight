#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,p;
    cin >> a >> p;
    if(a>=13) cout << p << endl;
    else if(a<=5) cout << 0 << endl;
    else cout << p/2 << endl;
    return 0;
}