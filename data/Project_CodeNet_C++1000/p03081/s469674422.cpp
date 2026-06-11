#include <bits/stdc++.h>

using namespace std;

int n, q;

string sir;

char t[200001], d[200001];


int isOutLeft(int mij)
{
    if(mij == n + 1)
        return 0;

    for (int j = 0; j < q; j++)
    {
        if(t[j] == sir[mij - 1])
        {
            if(d[j] == 'R')
                mij++;
            else
                mij--;
        }

        if(mij == n + 1)
            return 0;

        if(mij == 0)
            return 1;
    }

    return 0;
}

int BinarySearchLeft(int st, int dr)
{
    int ans;
    while(dr > st + 1)
    {
        int mij = (st + dr) / 2;

        if (isOutLeft(mij) || mij == 0)
            st = mij;
        else
            dr = mij;
    }

    ans = dr;
    return ans;
}


int isOutRight(int mij)
{
    if(mij == 0)
        return 0;

    for (int j = 0; j < q; j++)
    {
        if(t[j] == sir[mij - 1])
        {
            if(d[j] == 'R')
                mij++;
            else
                mij--;
        }

        if(mij == 0)
            return 0;

        if(mij == n + 1)
            return 1;
    }

    return 0;
}

int BinarySearchRight(int st, int dr)
{
    int ans;
    while(dr > st + 1)
    {
        int mij = (st + dr) / 2;

        if (isOutRight(mij) || mij == n + 1)
            dr = mij;
        else
            st = mij;
    }

    ans = dr;
    return ans;
}

int main()
{

    cin >> n >> q;
    cin >> sir;

    for(int i = 0; i < q; i++)
        cin >> t[i] >> d[i];

    int l = BinarySearchLeft(0, n + 1);
    int r = BinarySearchRight(0, n + 1);

    cout << r - l;

    return 0;
}
