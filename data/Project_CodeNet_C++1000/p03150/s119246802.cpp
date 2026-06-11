#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    string s;cin >> s;
    string k="keyence";
    if(s[0]!='k' && s[s.size()-1]!='e'){
        cout << "NO" << endl;
        return 0;
    }

    int f=0,l=0;

    for(int i = 1; i < 8; i++) {
        if(s.substr(0,i)==k.substr(0,i)) f=i;
        else break;
    }
    for(int i = 1; i < 8; i++){
        if(s.substr(s.size()-i)==k.substr(k.size()-i)) l=i;
        else break;
    }
    
    if(s[0]=='k' && s[s.size()-1]=='e'){
        if(f+l>=7){
            cout <<"YES" << endl;
            return 0;
        }
    }
    if(f>=7 || l>=7){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return 0;
}