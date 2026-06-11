#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    int N;
    cin >> N;
    string ans="Three";
    rep(i,N){
        char a;
        cin >> a;
        if(a=='Y'){
            ans="Four";
            break;
        }
    }
    cout << ans << endl;
}
