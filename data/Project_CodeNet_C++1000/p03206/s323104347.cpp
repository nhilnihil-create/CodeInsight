#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int d;
    cin>>d;
    if (d==22) {
        cout<<"Christmas Eve Eve Eve"<<endl;
    } else if(d==23) {
        cout<<"Christmas Eve Eve"<<endl;
    } else if(d==24) {
        cout<<"Christmas Eve"<<endl;
    } else {
        cout<<"Christmas"<<endl;
    }
}
