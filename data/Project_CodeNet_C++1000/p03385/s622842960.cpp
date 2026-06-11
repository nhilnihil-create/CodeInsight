
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    vector<int> a(3);
    rep(i,3){
        if(s.at(i)=='a') a.at(0) ++;
        else if(s.at(i)=='b') a.at(1) ++;
        else if(s.at(i)=='c') a.at(2) ++;
    }
    if(a[0]==1 && a[1]==1 && a[2]==1){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}