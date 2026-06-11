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

    int a[5];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int n,cnt=1,i=0;
    cin >>n;
    while (n) {
        i++;
        int x = n % 10;
        a[i] = x;
        n /= 10;
        if (i == 1)
            continue;
        if (x == a[i-1])
            cnt++;
        else
            cnt = 1;
        if (cnt >= 3) {
            cout <<"Yes";
            return 0;
        }
    }
    cout <<"No";



    return 0;
}
