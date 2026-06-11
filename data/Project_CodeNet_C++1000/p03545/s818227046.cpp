#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int sum;
    vector<int> d(3);
    vector<char> op(3);
    string s;

    cin >> s;

    rep(i,4){
        d[i] = s[i]-'0';
    }
    
    for(int bit = 0;bit < (1<<3);bit++){
        sum = d[0];
        for(int i = 0;i < 3;i++){
            if(bit & (1<<i)){
                sum += d[i+1];
                op[i] = '+';
            }
            else{
                sum -= d[i+1];
                op[i] = '-';
            }
        }
        if(sum == 7) break;
    }

    rep(i,4){
        cout << d[i];
        if(i < 3) cout << op[i];
    }

    cout << "=7" << endl;
    
    return 0;
}