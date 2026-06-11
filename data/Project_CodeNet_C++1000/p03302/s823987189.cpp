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

    int a, b;
    cin >> a >> b;

    if(a + b == 15){
        cout << "+" << endl;
    }else if(a * b == 15){
        cout << "*" << endl;
    }else{
        cout << "x" << endl;
    }

    return 0;
}

