#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int s;
    cin>>s;
    vector<int> A;
    int a = s;
    A.push_back(a);
    bool flag = false;
    for(int i=0;;i++){
        if(a%2 == 0){
            a = a/2;
        }else{
            a = 3*a+1;
        }
        A.push_back(a);
        if(a == 1 && flag) break;
        if(a == 1) flag = true;
    }

    rep(i, A.size()){
        FOR(j, i+1, A.size()){
            if(A[i] == A[j]){
                cout << j+1 << endl;
                return 0;
            }
        }
    }
}
