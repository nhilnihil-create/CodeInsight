#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){

    int n, a, b;
    cin >> n >> a >> b;

    if((b - a) % 2){
        cout << "Borys" << "\n";
    } else{
        cout << "Alice" << "\n";
    }

    return 0;
}
