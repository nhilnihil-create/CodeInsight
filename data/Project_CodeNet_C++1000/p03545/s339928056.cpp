#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

string n;
bitset<3> ans;
int main(){
    cin >> n;
    int sz = n.size();

    for(int bit=0; bit <(1 << sz-1); bit++){
        bitset<3> e(bit);
        int tmp=n.at(0)-'0';
        for(int i = 0; i < 3; i++){
            if(e.test(i)){
                tmp -= n.at(i+1) - '0';
            }else{
                tmp += n.at(i+1) - '0';
            }
        }
        if(tmp == 7) ans = e;
    }

    cout << n.at(0);
    for(int i = 0; i < 3; i++){
        if(ans.test(i)) cout << '-' << n.at(i+1);
        else cout << '+' << n.at(i+1);
    }
    cout << "=7" << endl;
}