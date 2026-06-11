#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,x,cnt = 0;
    cin >> N >> x;
    vector<int> a(N);

    rep(i, N){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    rep(i,N){

        if(x >= a[i]){
            x -= a[i];
            cnt++;
        }
    }

    if(x > 0 && cnt == N)
        cnt--;

    cout << cnt << endl;

    return 0;
}