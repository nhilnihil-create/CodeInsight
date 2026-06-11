#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int s;
    cin >> s;
    int now = s;
    vector<int> num(1000005);
    num[s]++;
    for(int i = 2; ; i++){
        if(now % 2 == 0) now /= 2;
        else now = now*3 + 1;
        if(num[now] == 1){
            cout << i << endl;
            return 0;
        }
        num[now]++;
    }
}