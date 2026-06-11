#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    int a,b, x;
    cin >> a >> b >> x;
    if(x < a){
        cout << "NO" << endl;
    }else{
        cout << (a + b >= x ? "YES" : "NO") << endl;
    }
}