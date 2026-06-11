#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;


vector<P> prime_factor(int n){
    vector<P> res;
    for(int p = 2; p * p <= n; p++){
        if(n % p != 0) continue;
        int num = 0;
        while(n % p == 0) {num++; n /= p;}
        res.push_back(P(p, num));
    }
    if(n != 1) res.push_back(P(n,1));
    return res;
} 
int n;
map<int, int> sisuu;

int rec(map<int,int>::iterator p, int mul){//autoは関数引数の型には使用できない。
    if(p == sisuu.end()){
        if(mul==1) return 1;//1通り
        else return 0;//mulは作れない。
    }
    int res = 0;
    for(int i = 0; i < p->second + 1; ++i){
        //1<=a<=A+1
        if(mul % (i+1) != 0) continue;
        res += rec(++p,mul/(i+1));//次以降の素数の指数を考える
        --p;
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 2; i <= n; ++i){
        //n!を素因数分解し、指数を計算
        auto ps = prime_factor(i);
        for(auto p : ps) sisuu[p.first] += p.second;
    }
    cout << rec(sisuu.begin(), 75) << endl;
}