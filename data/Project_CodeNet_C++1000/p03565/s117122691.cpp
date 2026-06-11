#include <iostream>
#include <ctime>
using namespace std;

string s,ss,t;
void input()
{
    cin >> ss >> t;
}

void solve()
{
    int Ns = ss.size(), Nt = t.size();
    for (int i = 0; i < Ns-Nt; ++i) {
        if(ss[i] == t[0]){
            for (int j = 0; j < Nt; ++j){
                if(ss[i+j] != '?' && ss[i+j] != t[j]) break;
            }
        }
    }
    for (int i = Ns-1; i >= Nt-1; --i){
        if(ss[i] == '?' || ss[i] == t[Nt-1]){
            s = ss;
            bool flag = true;
            for (int j = 0; j < Nt; ++j){
                if(ss[i-j] != '?' && ss[i-j] != t[Nt-1-j]) {
                    flag = false;
                    break;
                }
                ss[i-j] = t[Nt-1-j];
            }
            if(flag){
                for (int i = 0; i < Ns; ++i) {
                    if(ss[i] == '?') cout << 'a';
                    else cout << ss[i];
                }
                cout << endl;
                return;
            }
            ss = s;
        }
    }
    cout << "UNRESTORABLE" << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}