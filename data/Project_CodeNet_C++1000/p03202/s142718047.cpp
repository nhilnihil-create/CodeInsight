#include <bits/stdc++.h>
#define N 200005

using namespace std;

int n;
int a[N];
map < int , int > b;

bool ok(int mij)
{
    int i , k;

    b.clear();

    for(i = 2 ; i <= n ; i++)
        if(a[i] <= a[i - 1])
        {
            b.erase(b.upper_bound(a[i]) , b.end());
            k = a[i];
            ++b[k];

            while(k > 0 && b[k] == mij)
            {
                b.erase(k);
                ++b[--k];
            }

            if(!k)
                return false;
        }

    return true;
}

int main()
{
    int check = 0 , i;

    cin >> n;

    for(i = 1 ; i <= n ; i++)
    {
        cin>>a[i];
        check |= (a[i] <= a[i - 1]);
    }

    if(!check)
    {
        cout<<1;
        return 0;
    }

    int st = 2 , dr = n , mij = 0 , ans = 0;

    while(st <= dr)
    {
        mij = (dr - st) / 2 + st;

        if(ok(mij) == true)
        {
            ans = mij;
            dr = mij - 1;
        }
        else st = mij + 1;
    }

    cout<<ans;

    return 0;
}
