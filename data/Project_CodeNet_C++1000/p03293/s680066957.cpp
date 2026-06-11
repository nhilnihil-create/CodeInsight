#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    string s,t;
    cin >>s>>t;

    rep(i,t.size()){
        if(s==t){
            cout << "Yes"<<endl;
            return 0;
        }
        char tail = s[s.size()-1];
        for(int j = s.size()-1;j>0;j--){
            s[j] = s[j-1];
        }
        s[0] = tail;
    }

    cout << "No"<<endl;
}