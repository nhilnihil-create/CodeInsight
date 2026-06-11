#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())

int main()
{
    int n; cin >> n;
    bool flg = false;
    for (int cake = 0; cake < n; cake++) {
        for (int donut = 0; donut < n; donut++) {
            if(n == cake*4 + donut*7) flg = true;
        }
    }
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

}

/*
Ctrl+@
g++ a.cpp
./a.out
*/