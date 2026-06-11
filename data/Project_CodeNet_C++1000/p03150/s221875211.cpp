#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using vs = vector<string>;
const int MOD = 1000000007;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    string t="keyence";
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            string a = s.substr(0,i);
            if(j<n){
                string b = s.substr(j,n-j);
                a = a+b;
            }
            if(a==t){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}