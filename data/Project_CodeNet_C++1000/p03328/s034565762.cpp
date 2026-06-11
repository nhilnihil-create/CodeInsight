#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b;
    cin>>a>>b;
    int diff = b-a;
    int ah=0;
    for(int i =1;i<diff;i++){
        ah += i;
    }    
    cout<<ah-a<<endl;
}