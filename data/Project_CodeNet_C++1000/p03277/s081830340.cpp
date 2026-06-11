#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxN = 1e5 + 10;

int n;
int a[maxN], b[maxN], c[maxN], fen[maxN * 4];

void add(int pos, int val){
    for(int i = pos; i <= 2 * n; i += i&-i)
        fen[i] += val;
}

int get(int pos){
    int res = 0;
    for(int i = pos; i; i -= i&-i)
        res += fen[i];
    return res;
}

bool check(int x){
    memset(fen, 0, sizeof(fen));

    for(int i = 1; i <= n; ++i){
        if(a[i] >= x)
            b[i] = 1;
        else
            b[i] = -1;
    }

    int res = 0;

    add(n, 1);
    for(int i = 1; i <= n; ++i){
        b[i] += b[i - 1];
        res += get(b[i] + n);
        add(b[i] + n, 1);
    }

    return (res >= n * (n + 1) / 4);
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        c[i] = a[i];
    }

    sort(c + 1, c + n + 1);

    int high = unique(c + 1, c + n + 1) - c - 1;

    int low = 1, ans;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(check(c[mid])){
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }

    cout << c[ans];
}
