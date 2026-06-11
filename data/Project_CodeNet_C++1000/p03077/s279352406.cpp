#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    long n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;

    long slow = min(a, min( min(b,c) , min(d,e) ) );

    long slowstep;
    if(n % slow == 0) slowstep = n/slow;
    else slowstep = n/slow + 1;

    cout << 4 + slowstep << endl;
}   
