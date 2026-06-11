#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    if(n == 3) {
        cout << 2 << endl;
        cout << "1 3" << endl;
        cout << "2 3" << endl;
    }else{
        if(n%2) cout << (n-1)*(n-1)/2 << endl;
        else cout << n*(n-2)/2 << endl;
        int m = n-n%2;
        for(int i = 1;i < m/2;++i){
            for(int j = i+1;j <= m/2;++j){
                cout << i << " " << j << endl;
                cout << i << " " << m+1-j << endl;
                cout << m+1-i << " " << j << endl;
                cout << m+1-i << " " << m+1-j << endl;
            }
        }
        if(n%2){
            for(int i = 1;i < n;++i) cout << n << " " << i << endl;
        }
    }
}