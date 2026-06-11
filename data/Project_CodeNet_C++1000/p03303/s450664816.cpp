#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    string S;
    int w;
    cin >> S >> w;
    int cnt=0;
    for(int i=0; i<S.size(); i++){
        if(cnt>=S.size()) return 0;
        cout << S[cnt];
        cnt+=w;
    }
}