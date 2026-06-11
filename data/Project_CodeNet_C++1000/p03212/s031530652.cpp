#include<bits/stdc++.h>
using namespace std;

long long N;
long long res;

void solve(long long now,long long &res,long long cnt){
    if(now<=N){
        if(cnt == 0b111)res++;
    }
    else return;

    solve(now*10+3, res, cnt | 0b001);
    solve(now*10+5, res, cnt | 0b010);
    solve(now*10+7, res, cnt | 0b100);
}

int main(){
    cin>>N;
    res = 0;
    solve(0,res,0);
    cout<<res<<endl;
    return 0;
}