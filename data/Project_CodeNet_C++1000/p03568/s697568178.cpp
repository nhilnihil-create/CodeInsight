#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int n;
    cin >> n;
    int a[n];
    int count = 0;
    rep(i, n) { 
        cin >> a[i];
        if(a[i] % 2 == 0)
            count++;
    }
    cout << pow(3, n) - pow(2, count) << endl;
    return 0;
}