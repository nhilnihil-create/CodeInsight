#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int digits(ll m){
    int re = 0;
    while(m > 0){
        m /= 10;
        re++;
    }
    return re;
}
int main(){
    string s, t; cin >> s >> t;
    int n = s.size();
    bool flag = true;
    map<char,char> mas, mat;
    char a, b;
    for(int i = 0; i < n; i++){
        a = s[i];
        b = t[i];
        if(mas.count(a)){
            if(mas[a] != b) flag = false;
        }
        if(mat.count(b)){
            if(mat[b] != a) flag = false;
        }
        mas[a] = b;
        mat[b] = a;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}