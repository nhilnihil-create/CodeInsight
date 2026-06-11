#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main() {
    char a[10];
    rep(i,10) cin>>a[i];

    string year,month,day;
    
    rep(i,4) year += a[i];
    rep2(i,5,7) month += a[i];
    rep2(i,8,10) day += a[i];

    if(stoi(year)>=2020 || ( stoi(year)>=2019 && stoi(month)>=5 )) cout<<"TBD";
    else cout<<"Heisei"<<endl;
        
    return 0;
}