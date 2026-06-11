#include<bits/stdc++.h>
using namespace std;
string s;
int n, q;
char a[200010], b[200010];

bool binarySearch(int mid, int forward)
{
    int cur = mid;
    for(int i=1; i<=q; i++)
    {
        // cout << i << " " << cur << endl;
        if(s[cur] == a[i])
        {
            if(b[i] == 'L')
            {
                cur --;
            }
            else
            {
                cur ++;
            }
        }
        if((cur == n && !forward) || (cur == -1 && forward))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> q;
    cin >> s; 
    for(int i=1; i<=q; i++)
    {
        cin >> a[i] >> b[i];
    }

    int low = -1, high = n, mid;
    int forwardAns = -1;
    while(high - low > 1)
    {
        mid = (low + high)/2;
        if(binarySearch(mid, 1))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    forwardAns = high;

    low = -1, high = n;
    int backwardAns = n;
    while(high - low > 1)
    {
        mid = (low + high)/2;
        if(binarySearch(mid, 0))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    backwardAns = n - high;
    cout << n - (forwardAns + backwardAns) << endl;
    return 0;
}