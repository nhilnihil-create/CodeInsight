#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    string s;
    cin>>s;

    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));

    if(y < 2019){
        cout << "Heisei" << endl;
        return 0;
    }
    if(y == 2019){
        if(m < 4 || m == 4 && d <= 30){
            cout << "Heisei" << endl;
            return 0;
        }
    }

    cout << "TBD" << endl;
}
