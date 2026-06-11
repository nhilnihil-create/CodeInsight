#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}
void dfs(string s,int depth,int n,char alp[],int& ans,int b){
    if(depth <= n){
        if(s.find('3') <= 100 && s.find('5') <= 100 && s.find('7') <= 100){
            if(b >= stoi(s)) {
                ans++;
            }
        }
        for(int i = 0;i < 3;i++){
            s += alp[i];
            depth++;
            dfs(s,depth,n,alp,ans,b);
            s.erase(s.size()-1);
            depth--;
        }
    }
}



int main(){
    string a; cin >> a;
    string s = "";
    vector<int>v;
    int ans = 0;
    char alp[3] = {'3','5','7'};
    int depth = 0;
    dfs(s,depth,(int)a.length(),alp,ans,stoi(a));
    cout << ans;
}

