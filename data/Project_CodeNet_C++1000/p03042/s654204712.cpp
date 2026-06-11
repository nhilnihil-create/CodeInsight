#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

bool ok(int x){
    if(0<x && x<=12) return true;
    else return false;
}

int main(void){
    int s;
    cin>>s;
    int l=s/100,r=s%100;
    if(ok(l)){
        if(ok(r)) puts("AMBIGUOUS");
        else puts("MMYY");
    }
    else{
        if(ok(r)) puts("YYMM");
        else puts("NA");
    }
    return 0;
}