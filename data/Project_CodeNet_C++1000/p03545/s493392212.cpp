#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> x(4);
    rep(i, 4) x[i] = s[i] - '0';
    if(x[0] + x[1] + x[2] + x[3] == 7){
        printf("%d+%d+%d+%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] + x[1] + x[2] - x[3] == 7){
        printf("%d+%d+%d-%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] + x[1] - x[2] + x[3] == 7){
        printf("%d+%d-%d+%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] + x[1] - x[2] - x[3] == 7){
        printf("%d+%d-%d-%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] - x[1] + x[2] + x[3] == 7){
        printf("%d-%d+%d+%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] - x[1] + x[2] - x[3] == 7){
        printf("%d-%d+%d-%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] - x[1] - x[2] + x[3] == 7){
        printf("%d-%d-%d+%d=7", x[0], x[1], x[2], x[3]);
    }else if(x[0] - x[1] - x[2] - x[3] == 7){
        printf("%d-%d-%d-%d=7", x[0], x[1], x[2], x[3]);
    }
    cout << endl;

    return 0;
}