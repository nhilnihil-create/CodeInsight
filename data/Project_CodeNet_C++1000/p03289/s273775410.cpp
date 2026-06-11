#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    string S;cin >> S;
    string ans = "AC";
    if(S[0] != 'A') ans = "WA";
    int c=0;
    for(int i=1;i<S.size();i++){
        if(!islower(S[i]) && S[i] != 'C') ans="WA";
        if(2 <= i && i <= S.size()-2 && S[i] == 'C') c++;
    }
    if(c!=1) ans="WA";
    cout << ans << endl;
}

