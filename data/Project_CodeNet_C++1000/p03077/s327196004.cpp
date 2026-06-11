/**
*    author:  souzai32
*    created: 02.08.2020 19:29:14
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    long long int n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;

    long long int time=0;
    long long int t=min(a,min(b,min(c,min(d,e))));
    if(n%t) time++;
    time+=n/t+4;

    cout << time << endl;

    return 0;
}