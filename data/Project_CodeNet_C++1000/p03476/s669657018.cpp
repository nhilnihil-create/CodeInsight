#include <bits/stdc++.h>
using namespace std;
using ll = long long;



vector<bool> IsPrime(int N){
    vector<bool> isprime(N+1, true);

    isprime[1] = false;
    for (int i = 2; i*i <= N; i++)
    {
        if(isprime[i] == true){
            int j = 2;
            while (i*j <= N)
            {
                isprime[i*j] = false;
                j++;
            }
        }
    }
    return isprime;
}

int main(void)
{
    int Q;
    cin >> Q;
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<bool> isprime = IsPrime(1e5);
    
    vector<int> counts(1e5+1, 0);

    counts[0] = 0;
    counts[1] = 0;
    for (int i = 2; i <= 1e5; i++)
    {
        bool primself = isprime[i];
        counts[i] = counts[i-1];

        if((i+1) % 2 == 0){
            bool halfPrime = isprime[(i+1)/2];
            if(primself & halfPrime){
                counts[i]++;
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cout << counts[r[i]] - counts[l[i]-1] << endl;
    }
    
    
    return 0;
}
