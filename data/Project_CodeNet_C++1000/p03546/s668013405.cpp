#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define n1		      "\n"
#define B                     begin()
#define E                     end()
#define F                     first
#define S                     second
#define pb                    push_back
#define pf                    push_front
#define popb                  pop_back()
#define popf                  pop_front()

const int BIG=1e5+55;
const int BIGG=1e9+7;
const ll BIGGE=1e12+55;
const double SML=(1e-7);

using namespace std;

    int a[100][100];
    ll ans;

void floyd() {
    for (int k=0; k<=9; ++k) {
        for (int i=0; i<=9; ++i) {
            for (int j=0; j<=9; ++j) {
                a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >>n >>m;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            cin >>a[i][j];
    floyd();
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            int x;
            cin >>x;
            if (x == 1 || x == -1)
                continue;
            ans += a[x][1];
        }
    cout <<ans <<n1;


    return 0;
}
