#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int a[5],k;
    rep(i,5) cin >> a[i];
    cin >> k;
    bool flag = true;
    rep(i,5){
        for(int j = i + 1; j < 5; j++) {
//            cout << a[j] - a[i] << endl;
            if((a[j] - a[i]) > k) flag = false;
        }
    }
    cout << (flag ? "Yay!" : ":(") << endl;

}
