#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    int s = 111;
    for(int i = 1;i<10;i++){
        if(s*i >= n){
            cout << s*i << endl;
            return 0;
        }
    }
}