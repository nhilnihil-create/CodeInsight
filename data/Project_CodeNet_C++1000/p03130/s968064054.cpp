#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    
    int a,b;
    int counter[4];
    rep(i,4){
        counter[i] = 0;
    }
    rep(i,3){
        cin >> a >> b;
        counter[a-1]++;
        counter[b-1]++;
    }
    rep(i,4){
        if(counter[i]>=3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}