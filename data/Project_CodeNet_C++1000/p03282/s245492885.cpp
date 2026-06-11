
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    ll k;
    cin >> s >> k;
    bool is1=true;
    for(int i=0; i<k; i++){
        //1以外の要素が出てきたらそれを記録してbreak
        if(s[i] !='1'){
            cout << s[i] << endl;
            return 0;
        }
        //文字列の最後まで来たらbreak
        if(i == s.size()-1){
            break;
        }
    }

    cout << 1 << endl;
    return 0;
    

}