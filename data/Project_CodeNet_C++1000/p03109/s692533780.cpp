#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    string s;
    cin >> s;
    int ymd=0;
    rp(i,10){
        if(i==4||i==7) continue;
        ymd=ymd*10+(s.at(i)-'0');
    }
    if(ymd<20190431) puts("Heisei");
    else puts("TBD");
    return 0;
}