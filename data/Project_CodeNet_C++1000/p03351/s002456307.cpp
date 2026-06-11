#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<< (((abs(b-a)<=d && abs(c-b)<=d) || abs(c-a)<=d)? "Yes" : "No") <<endl;

    return 0;
}
