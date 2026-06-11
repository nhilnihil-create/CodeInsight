#include <bits/stdc++.h>
#define LL long long
#define rep1(i,a,b) for (int i = a;i <= b;i++)

using namespace std;

const int N = 1e5;
const int NN = 2e5;
const int O = 1e5+1;

int n,a[N+10],temp[N+10];
LL cnt;

struct BI {
    LL a[NN + 10];

    int lowbit(int x) {
        return x&(-x);
    }

    void add(int x,int y) {
        while (x <= NN) {
            a[x] += y;
            x += lowbit(x);
        }
    }

    LL sum(int x) {
        LL now = 0;
        while (x > 0) {
            now += a[x];
            x -= lowbit(x);
        }
        return now;
    }

    LL get_sum(int l, int r) {
        if (l>r) return 0;
        return sum(r) - sum(l - 1);
    }

}b;


bool ok(int x){
    for (int i = 0;i <= NN;i++) b.a[i] = 0;
    for (int i = 1;i <= n;i++)
        if (a[i]>=x)
            temp[i]=1;
        else if (a[i]<x)
            temp[i]=-1;
    for (int i = 1;i <= n;i++) temp[i]+=temp[i-1];
    LL ju1 = 0;
    b.add(O,1);
    for (int i = 1;i <= n;i++){
        ju1+=b.get_sum(0,O+temp[i]);
        b.add(temp[i]+O,1);
    }
    //中位数大于等于x的区间的个数为ju1
    //x越大,ju1越小
    if (ju1>=(cnt+1)/2)
        return true;
    else
        return false;
}

int main()
{
    #ifdef LOCAL_DEFINE
        freopen("rush.txt","r",stdin);
    #endif // LOCAL_DEFINE
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    cnt = 1LL*n*(n-1)/2+n;
    int l= 1,r = 0,temp = -1;
    rep1(i,1,n) {
        cin >> a[i];
        r = max(r,a[i]);
    }
    while (l<=r){
        int mid = (l+r)>>1;
        if (ok(mid)){
            l = mid + 1;
            temp = mid;
        }else
            r = mid -1;
    }
    cout<<temp<<endl;
    return 0;
}
