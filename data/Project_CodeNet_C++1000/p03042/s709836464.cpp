#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    cin >> s;
    int s1 = stoi(s.substr(0,2));
    int s2 = stoi(s.substr(2,4));
    
    bool yymm = s2 <=12 && s2>0;
    bool mmyy = s1 <=12 && s1>0;

    if(yymm && mmyy){
        cout << "AMBIGUOUS" <<endl;
    }else if(yymm){
        cout << "YYMM" << endl;
    }else if(mmyy){
        cout << "MMYY" << endl;
    }else{
        cout << "NA" << endl;
    }
}