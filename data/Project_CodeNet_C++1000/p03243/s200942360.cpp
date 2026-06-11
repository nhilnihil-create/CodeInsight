#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    
    int N;
    cin >> N;

    vector<int> v{111, 222, 333, 444, 555, 666, 777, 888, 999, 1111};
    int a,b,c;
    a=N/100; int n = N%100;
    b =n/10;
    c =n%10;

    if(a==b && b==c){
        cout<<N<<endl;
    }else{
        rep(i,v.size()){
            if(v[i]>N){
                cout<<v[i]<<endl;
                return 0;
            }
        }
    }
}