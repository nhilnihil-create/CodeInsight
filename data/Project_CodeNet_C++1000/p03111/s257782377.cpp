#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

const int INF = 100000000;

int N,A,B,C,a,b,c; vector<int> l;
void input()
{
    cin >> N >> a >> b >> c;
    l.resize(N);
    for(int i=0; i<N; ++i) cin >> l[i];
}

void f(int l)
{
    if(l==6){ A = a; B = b; C = c;}
    if(l==5){ A = a; B = c; C = b;}
    if(l==4){ A = b; B = a; C = c;}
    if(l==3){ A = b; B = c; C = a;}
    if(l==2){ A = c; B = a; C = b;}
    if(l==1){ A = c; B = b; C = a;}
    return;
}

void solve()
{
    int loop = 6;
    int MIN = INF;
    while(loop > 0){
        f(loop);
        bitset<8> bts(0),A_bts,B_bts,C_bts;
        int min_A = INF, min_B = INF, min_C = INF;
        for(int i=1; i<(1<<N); ++i){
            bts = i;
            int sum = 0, mp = -1;
            for(int j=0; j<N; ++j){
                if(bts[j] == 1) {
                    sum += l[j];
                    ++mp;
                }
            }
            if(min_A > abs(A-sum) + mp*10){
                A_bts = bts;
                min_A = abs(A-sum) + mp*10;
            }
        }
        // cout << min_A << " " << A_bts << endl;

        for(int i=1; i<(1<<N); ++i){
            bts = i; 

            bool flag = false;
            for(int j=0; j<N; ++j){
                if((bts[j] & A_bts[j]) == 1){
                    flag = true; break;
                }
            }
            if(flag) continue;

            int sum = 0, mp = -1;
            for(int j=0; j<N; ++j){
                if(bts[j] == 1) {
                    sum += l[j];
                    ++mp;
                }
            }
            if(min_B > abs(B-sum) + mp*10){
                B_bts = bts;
                min_B = abs(B-sum) + mp*10;
            }
        }
        // cout << min_B << " " << B_bts << endl;

        for(int i=1; i<(1<<N); ++i){
            bts = i; 

            bool flag = false;
            for(int j=0; j<N; ++j){
                if((bts[j] & (A_bts[j] | B_bts[j])) == 1){
                    flag = true; break;
                }
            }
            if(flag) continue;

            int sum = 0, mp = -1;
            for(int j=0; j<N; ++j){
                if(bts[j] == 1) {
                    sum += l[j];
                    ++mp;
                }
            }
            if(min_C > abs(C-sum) + mp*10){
                C_bts = bts;
                min_C = abs(C-sum) + mp*10;
            }
        }
        // cout << min_C << " " << C_bts << endl;

        --loop;
        // cout << endl;

        MIN = min(MIN,min_A + min_B + min_C);
    }
    cout << MIN << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}