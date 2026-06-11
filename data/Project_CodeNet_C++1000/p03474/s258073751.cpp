#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int a,b;
    string s;
    cin >> a >> b;
    cin >> s;
    if(s.size()!=a+b+1){
        cout << "No" << endl;
        return 0;
    }
    rep(i,s.size()){
        if(i<a){
            if(s[i]>='0'&&s[i]<='9'){
                continue;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }else if(i==a){
            if(s[i]!='-'){
                cout << "No" << endl;
                return 0;
            }
        }else{
            if(s[i]>='0'&&s[i]<='9'){
                continue;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}