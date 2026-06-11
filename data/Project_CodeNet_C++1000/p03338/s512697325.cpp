#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int N; string S;

int func(string S1, string S2){
    int ans =0;
    map<char,int> L{};
    map<char,int> R{};
    for(int i=0;i<S1.size();i++) L[S1[i]]=1;
    for(int i=0;i<S2.size();i++) R[S2[i]]=1;
    for(auto i=L.begin(); i!=L.end(); i++){
        char key = i ->first;
        ans += L[key]*R[key];
    }
    return ans;
}

int main() {
    cin >> N; cin >> S;
    int ans = 0;
    int len = S.size();
    for(int i=1;i<len-1; i++){
        int n = func(S.substr(0,i), S.substr(i,len-i));
        if(n > ans) ans = n;
    }
    cout << ans << endl;
}
