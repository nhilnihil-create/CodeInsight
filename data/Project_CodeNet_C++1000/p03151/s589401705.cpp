#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll asum = 0;
    ll bsum = 0;
    vector<ll> margin(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        asum += (ll) A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
        bsum += (ll) B[i];
        margin[i] = A[i] - B[i];
    }

    if(asum < bsum){
        cout << -1 << endl;
        return 0;
    }

    ll sum1= 0;
    ll num = 0;
    for (int i = 0; i < N; i++){
        if(margin[i] >= 0){
            
        } else {
            sum1 -= margin[i];
            num++;
        }
    }

    sort(margin.begin(), margin.end(), greater<ll>());

    for (int i = 0; i < N; i++)
    {
        if(sum1 <= 0) break;
        if(margin[i] > 0){
            sum1 -= margin[i];
            num++;
        }
    }
    
    cout << num << endl;
    return 0;
}
