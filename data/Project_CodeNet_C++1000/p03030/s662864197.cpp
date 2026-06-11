#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <tuple <string ,int ,int>> m;
    string s;
    int ss,j;
    rep(i,n){
        cin >> s >> ss;
        ss=-ss;
        j=i+1;
        m.push_back(tie(s,ss,j));
    }

    sort(m.begin(),m.end());

    rep(i,n){
        cout << get<2>(m[i]) << endl;
    }
    

    return 0;
}