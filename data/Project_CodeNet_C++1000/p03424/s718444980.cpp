#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int N;
    cin >> N;
    vector<char> S(N);
    bool a=false;
    rep(i,N){
        cin >> S.at(i);
        if(S.at(i)=='Y') a=true;
    }
    if(a)cout << "Four" << endl;
    else cout << "Three" << endl;
}