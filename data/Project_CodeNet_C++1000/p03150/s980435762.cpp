#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    string S; cin >> S;
    string key = "keyence";
    int count = 0;
    int len = min(int(S.size()), 7);
    for(int i=0;i<len;i++){
        if(S[i] == key[i]) count++;
        else break;
    }
    for(int i=0;i<len;i++){
        if(S[S.size()-1-i] == key[6-i]) count++;
    }
    if (count >=7) cout << "YES" << endl;
    else cout << "NO" << endl;
}
