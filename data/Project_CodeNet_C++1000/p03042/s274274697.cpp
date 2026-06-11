#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

bool isyymm(string x){
    string a = x.substr(2,4);
    if(atoi(a.c_str()) > 0 && atoi(a.c_str()) <= 12){
        return true;
    }else{
        return false;
    }
}

bool ismmyy(string x){
    string a = x.substr(0,2);
    if(atoi(a.c_str()) > 0 && atoi(a.c_str()) <= 12){
        return true;
    }else{
        return false;
    }
}


int main() {
    string s; cin >> s;
    if(isyymm(s)&&ismmyy(s)){
        cout << "AMBIGUOUS";
    }else if(isyymm(s)){
        cout << "YYMM";
    }else if(ismmyy(s)){
        cout << "MMYY";
    }else{
        cout << "NA";
    }
}


