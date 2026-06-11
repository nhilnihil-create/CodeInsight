#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    if(n == 1)cout << "Hello World" << endl;
    else{
        int a, b; cin >> a>> b; cout <<a+b << endl;
    }
    return 0;
}