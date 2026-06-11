#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x = max({a,b,c});
    int s = a+b+c;

    if(x%2 != s%2)
        x++;
    
    cout << (3*x - s)/2;
}
