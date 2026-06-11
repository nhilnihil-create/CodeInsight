#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

//curnum現在の数字,use3,5,7を使ったかどうか,nownumカウント
ll func(ll curnum, int use,ll &cnt) {
    if(curnum > n) return cnt;
    if(use == 0b111)++cnt;

    func(curnum*10+3, use | 0b001, cnt);
    func(curnum*10+5, use | 0b010, cnt);
    func(curnum*10+7, use | 0b100, cnt);

}

int main() {
 cin >> n;
 ll res=0;
 cout << func(0,0,res) << endl;

}
