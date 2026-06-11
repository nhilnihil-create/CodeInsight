#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    int p = 0;
    for(int i = a;i < max(c,d);i++){
        if(s[i] == '#' && s[i-1] == '#'){
            p++;
            break;
        }
    }
    if(d < c){
        p++;
        for(int i = b;i <= d;i++){
            if(s[i] == '.' && s[i-1] == '.' && s[i-2] == '.'){
                p--;
                break;
            }
        }
    }
    if(p == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
