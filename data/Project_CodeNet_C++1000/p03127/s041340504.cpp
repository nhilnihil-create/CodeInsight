#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin>>N;
    int A[N];
    rep(i, 0, N) {
        cin>>A[i];
    }
    sort(&A[0], &A[N]);
    int old=0;
    while (old!=A[0]) {
        old=A[0];
        rep(i, 1, N) {
            int tmp=A[i]%A[0];
            if (tmp) {
                A[i]=tmp;
            }
        }
        sort(&A[0], &A[N]);
    }
    cout<<A[0]<<endl;
}
int main()
{
    func();
}