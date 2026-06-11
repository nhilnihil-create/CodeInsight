#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    char a, b;
    cin >> a >> b;

    if(a > b) {
        cout << ">" << endl;
    }else if(a < b){
        cout << "<" << endl;
    }else{
        cout << "=" << endl;
    }


    return 0;
}

