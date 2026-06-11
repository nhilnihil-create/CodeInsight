
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string n;
    cin >> n;
    bool good=false;
    if(n[0]==n[1] && n[1]==n[2]) good=true;
    if(n[1]==n[2] && n[2]==n[3]) good=true;
    if(good){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}