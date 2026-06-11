#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}


class BIT{
private:
    //[1,n]
    vector<int> bit;
    int n;

public:
    BIT(){}
    BIT(int size){
        n = size;
        bit = vector<int>(n+1,0);
    }
    //[0,i)のsum（内部実装は[1,i]）
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
    void show(){
        for(int i = 1; i <= n; i++){
            cout << " " << bit[i];
        }
        cout << endl;
    }
};

signed main(void) {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n)cin >> a[i];
    int l = 0, r = 1<<30;
    int geta = n+1;
    int tmp = (n+1)*n/2/2;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        int num = 0;
        BIT bit(n*2+10);
        int sum = 0;
        bit.add(sum+geta, 1);
        rep(i,n){
            int t = a[i]<=mid?1:-1;
            sum += t;
            num += bit.sum(sum+geta-1);
            bit.add(sum+geta, 1);
        }
        if(num > tmp) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
