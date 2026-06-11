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

    ll a[100];
    int n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    a[0] = 2;
    a[1] = 1;
    for (int i=2; i<=86; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    cin >>n;
    cout <<a[n];



    return 0;
}
