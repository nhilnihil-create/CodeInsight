#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())
const int INF = 1001001001;

int digit_sum(int n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        //↑合計 ↓桁数
        //res++;
        n /= 10;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    int mn=INF;
    for(int a=1; a<n; a++){
        int b = n - a;
        mn = min(mn,digit_sum(a) + digit_sum(b));
    }
    cout << mn << endl;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/