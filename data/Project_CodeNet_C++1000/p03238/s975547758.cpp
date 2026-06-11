#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    if(n == 1){
        cout << "Hello World" << endl;
    }else{
        int a, b; cin >> a >> b;
        cout << a+b << endl;
    }
    return 0;
}