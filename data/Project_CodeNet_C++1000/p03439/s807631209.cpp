#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N; cin >> N;
    string res;
    int beg, end; //male -> 0, female -> 1
    int l, mid, r;
    l = 0; r = N-1;
    rep(i, 20){
        if(i == 0) {cout << 0 << endl; flush(cout);}
        else{
            cin >> res;
            if(i == 1){
                if(res == "Male") beg = 0;
                else if(res == "Female") beg = 1;
                else return 0;

                cout << N-1 << endl;
                flush(cout);
            }
            else if(i == 2){
                if(res == "Male") end = 0;
                else if(res == "Female") end = 1;
                else return 0;

                mid = N/2;
                cout << mid << endl;
                flush(cout);
            }
            else{
                int cur;
                if(res == "Male") cur = 0;
                else if(res == "Female") cur = 1;
                else return 0;

                //curはmidがMaleかFemaleかを示している
                //mid-lが偶数ならbeg=curであるべき
                bool same_beg_mid;
                if((mid-l) % 2 == 0) same_beg_mid = true;
                else same_beg_mid = false;
                if((same_beg_mid && beg == cur) || (!same_beg_mid && beg != cur)){
                    //前半は正しいとき
                    beg = cur;
                    l = mid;
                }
                else{
                    end = cur;
                    r = mid;
                }
                mid = (l+r) / 2;
                cout << mid << endl;
                flush(cout);
            }
        }
    }
    return 0;
}

void solve(){}