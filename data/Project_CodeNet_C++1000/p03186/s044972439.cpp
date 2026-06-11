#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    ll A, B, C; cin >> A >> B >> C;
    //C基準
    if(C > (B + A)){
        cout << A + B + B + 1 << endl;
    }else if(C <= (B + A)){
        cout << C + B << endl;
    }
}
