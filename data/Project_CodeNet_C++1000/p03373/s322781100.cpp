#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define _GLIBCXX_DEBUG


int main(){
int a,b,c,x,y;
cin >> a >> b >> c >> x >> y;
int sum = 1000000000;


rep(r,200000){
    int p =max(0,x-r/2);
    int q =max(0,y-r/2);
    sum = min(a*p+b*q+c*r,sum);
}



cout << sum << endl;
}
