#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

struct Nbase {
    int base;
    int sz = 1;
    long long Max = 1e18;

    Nbase(int k = 2){
        base = k;
        while(Max != 0){
            Max /= abs(base);
            sz++;
        }
    }

    //繰り返し二乗法
    long long EX(long long x,long long n){
        if(n == 0) return 1;
        else if(n%2 == 1) return EX(x,n-1)*x;
        else return EX(x*x,n/2);
    }
    
    vector<int> Xor_all_2(long long n){
        vector<int> ret(sz,0);
        long long modf = 2;
        for(int i = 0; i < sz; i++){
            ret[i] = (((n+1)/modf)*(modf/2))%2+max(((n+1)%modf-modf/2)%2,(long long)0);
            ret[i] %= 2;
            if(n%modf == n) break;
            modf *= 2;
        }
        return ret;
    }

    vector<int> to_np(long long num){
        vector<int> ret(sz);
        long long subtraction = EX(base,sz-1);
        for(int i = sz-1; i >= 0; i--){
            long long quotient = num/subtraction;
            ret[i] = quotient;
            num -= ret[i]*subtraction;
            subtraction /= base;
        }
        return ret;
    }

    long long re_n(vector<int>& vec){
        long long ret = 0;
        vec.resize(sz);
        for(int i = 0; i < sz; i++){
            ret += vec[i]*EX(base,i);
        }
        return ret;
    }

    void supress(const vector<int>& lim,vector<int>& at){
        bool upper = true;
        for(int i = sz-1; i >= 0; i--){//!sz -> sz-1
            if(upper && lim[i] > 0) upper = false;
            if(lim[i] > at[i]) break;
            else if(upper || lim[i] < at[i]) at[i] = lim[i];
        }
    }

    void remove(vector<int>& num){
        num.resize(sz);
        for(int i = sz-1; i > 0; i--){
            if(num[i] == 0) num.pop_back();
            else break;
        }
    }
};

int main(){
    Nbase base = 2;
    ll a,b;
    cin >> a >> b;
    vector<int> A = base.Xor_all_2(max(a-1,(ll)0));
    vector<int> B = base.Xor_all_2(b);
    a = base.re_n(A);
    b = base.re_n(B);
    cout << (a^b) << endl;
    return 0;
}