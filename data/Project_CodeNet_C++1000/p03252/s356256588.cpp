#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string S, T; cin >> S >> T;
    vector<int> s(26, -1);
    vector<int> g(26, -1);
    for(int i = 0; i < S.size(); ++i){
        int a = S[i] - 'a';
        int b = T[i] - 'a';
        if(s[a] != -1 || g[b] != -1){
            if(s[a] != b || g[b] != a){
                cout << "No" << endl;
                return 0;
            }
        }else{
            s[a] = b;
            g[b] = a;
        }
    }
    cout << "Yes" << endl;
}