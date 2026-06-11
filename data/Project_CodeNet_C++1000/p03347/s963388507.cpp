///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int maxn = 2000* 100 + 5;
int a[maxn];

int32_t main(){
    int n, ans = 0;
    cin >>n;
    for(int i = 0; i < n; i ++){
        cin >>a[i];
    }
    for(int i = n - 1; i >= 0; i --){
        if(a[i] < a[i + 1] - 1)
            return cout <<-1 <<endl, false;
        if(a[i] == a[i + 1] - 1)
            ans ++;
        else if(a[i] >= a[i + 1])
            ans += a[i + 1];
    }
    if(a[0] > 0)
        return cout <<-1 <<endl, false;
    cout <<ans <<endl;
    return false;
}
