#include<bits/stdc++.h>

using namespace std;
int n;
long long k, a, b;
vector<pair<int, int>> parovi;
int mod = 998244353;
vector<int> faktorijele;

int add(int a, int b){
    a += b;
    if (a >= mod)return a-mod;
    else return a;
}
int sub(int a, int b){
    a-=b;
    if (a < 0){
        return a+mod;
    }else{
        return a;
    }
}
int mul(int a, int b){
    return ((long long)a*b)%mod;
}
int potenciranje(int b, int x){
    if(x == 0)return 1;
    if(x == 1)return b;
    int a = potenciranje(b, x/2);

    if (x%2==0)return mul(a, a) ;
    else return mul(mul(a, a), b);
}
int divi(int a, int b){
    return mul(a, potenciranje(b, mod-2));
}
void generejt(){
    int faktorijela = 1;
    faktorijele.push_back(1);
    for (int i = 1; i < 500000; ++i){
        faktorijela = mul(faktorijela, i);
        faktorijele.push_back(faktorijela);
    }
}
int main()
{
    generejt();
    cin >>n >>a >>b >>k;
    for (int i = 0; i <= n; ++i){
        long long umn = a*i;
        if (umn > k) break;
        if ((k-umn) % b == 0) {
            long long j = (k - umn) / b;
            if (j > n) continue;
            parovi.push_back({i, j});
        }
    }
    int sol = 0;
    for (int i = 0; i < parovi.size(); ++i){
        int pr = (divi(faktorijele[n], mul(faktorijele[parovi[i].first], faktorijele[n - parovi[i].first])));
        int dr = (divi(faktorijele[n], mul(faktorijele[parovi[i].second], faktorijele[n - parovi[i].second])));
        ///cout <<faktorijele[n] <<" " <<faktorijele[parovi[i].first] <<" " <<faktorijele[parovi[i].second] <<endl;
        ///cout <<parovi[i].first <<" " <<parovi[i].second <<" " <<pr <<" " <<dr <<endl;
        sol = add(sol, mul(pr, dr));
    }
//    for (int i = 0; i < 20; ++i)cout <<faktorijele[i] <<" ";
    /*
    cout <<endl;
    cout <<add(2, 2) <<endl;
    cout <<sub(5, 10)<<endl;
    cout <<mul(2, 2)<<endl;
    cout <<divi(8, 2)<<endl;
    cout <<potenciranje(2, mod-2) <<endl;
    */
    cout <<sol;
return 0;
}
