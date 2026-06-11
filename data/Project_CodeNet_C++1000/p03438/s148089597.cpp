#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<N;i++)
    {
        cin >> B[i];
    }

    vector<ll> timesOfPlus(N,0);

    for(int i=0;i<N;i++)
    {
        timesOfPlus[i] = max(0LL,((B[i]-A[i]+1)/2));
        A[i] += 2 * timesOfPlus[i];
    }

    ll Dif = 0;

    for(int i=0;i<N;i++)
    {
        Dif += (A[i] - B[i]);
    }

    if(accumulate(ALL(timesOfPlus),0LL) < Dif)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}