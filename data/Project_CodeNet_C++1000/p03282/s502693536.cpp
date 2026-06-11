#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

const int MOD = 1000000007;
const int INF = 1001001001;

int main(){
    string s;
    ll k;
    cin>>s>>k;
    
    if(k<=s.size()){
        int nmin = 1;
        for(int i=0; i<k; i++){
            nmin = max(nmin, s[i]-'0');
        }
        if(nmin==1){
            cout<<1<<endl;
            return 0;
        }
    }
    
    for(int i=0; i<s.size(); i++){
        if(s[i]!='1'){
            cout << s[i] << endl;
            break;
        }
    }
    
    return 0;
}