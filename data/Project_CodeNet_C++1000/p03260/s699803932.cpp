#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int A, B;
    cin >> A >> B;
    bool res = true;
    if(A*B % 2 == 0) res = false;
    string ans;
    if(res){
        ans = "Yes";
    }else{
        ans = "No";
    }
    cout << ans << endl;
}