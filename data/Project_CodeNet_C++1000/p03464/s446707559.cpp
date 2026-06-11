#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int a[maxn];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);

    if(a[n] != 2){
        cout<<-1<<endl;
        return 0;
    }
    long long mn = 2, mx = 2;
    for(int i=n;i;i--) {
        long long x = mn / a[i] + (mn %a[i] != 0), y = mx/a[i];
        if(y * a[i] < mn) {
            cout<<-1<<endl;
            return 0;
        }
        mn = x * a[i];
        mx = (y * a[i]) + a[i] - 1;
    }
    cout<<mn<<' '<<mx<<endl;
    return 0;
}
