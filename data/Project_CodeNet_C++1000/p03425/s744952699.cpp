#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin>>N;
    string tmpstr;
    int array[5]={};
    rep(i, 0, N) {
        cin>>tmpstr;
        if (tmpstr[0]=='M')++array[0];
        else if (tmpstr[0]=='A')++array[1];
        else if (tmpstr[0]=='R')++array[2];
        else if (tmpstr[0]=='C')++array[3];
        else if (tmpstr[0]=='H')++array[4];
    }
    ll ans=0;
    rep(i, 0, 5) {
        rep(j, i+1, 5) {
            rep(k, j+1, 5) {
                ans+=(ll)array[i]*(ll)array[j]*(ll)array[k];
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    func();
}