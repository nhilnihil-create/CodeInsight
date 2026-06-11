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
    int n,x; cin >> n >> x;
    vector<int> m(n); rep(i, n) cin >> m[i];
    Sort(m);
    rep(i,n) x -= m[i];
    cout << n + x/m[0] << endl;

}

/*
Ctrl+@
g++ a.cpp
./a.out
*/