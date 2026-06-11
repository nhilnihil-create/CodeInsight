#include<bits/stdc++.h>
using namespace std;
vector<int> primes(100001,1);

void prime()
{
    primes[1]=0;
    int fac=2;
    for (int i=2*fac;i<100001;i+=fac)
    {
        primes[i]=0;
    }
    fac++;
    while (fac<100001)
    {
        if (primes[fac]==1)
        {
            for (int i=2*fac;i<100001;i+=fac)
            {
                primes[i]=0;
            }
        }
        fac+=2;
    }
}

int main()
{
    prime();
    int Q;cin >> Q;
    int l,r;
    vector<int> likenum(100001,0);
    for (int i=3;i<100001;i+=2)
    {
        if (primes[i] && primes[(i+1)/2])
        {
            likenum[i]=1+likenum[i-2];
        }
        else likenum[i]=likenum[i-2];
        //cout << likenum[i] << endl;
    }
    for (int i=0;i<Q;i++)
    {
        cin >> l >> r;
        if (primes[l] && primes[(l+1)/2]) cout << likenum[r]-likenum[l]+1 << endl;
        else cout << likenum[r]-likenum[l] << endl;
    }
    return 0;
}