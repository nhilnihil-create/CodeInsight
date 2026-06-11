#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int dx[] = {1, -1, 0, 0};
int dy[] = {0 ,0, 1, -1};

int main(){
    int a, b;
    cin >> a >> b;
    if(a > b){
        cout << a - 1 << endl;
    }
    else cout << a << endl;
}