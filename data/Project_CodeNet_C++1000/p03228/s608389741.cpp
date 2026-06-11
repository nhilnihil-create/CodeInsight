//1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,k;
    cin >> a >> b >> k;
    for(int i = 0;i < k;i++){
        b += a = a/2;
        swap(a, b);
    }
    if(k%2)swap(a,b);
    cout << a << " " << b << endl;
}