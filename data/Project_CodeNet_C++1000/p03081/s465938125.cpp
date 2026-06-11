#include<bits/stdc++.h>
using namespace std;
string s;
int n, q;
char a[200010], b[200010];
 
bool binarySearch(int mid, int forward)
{
    if(mid > n-1 || mid < 0)
    {
        return 1;
    }
    int cur = mid;
    int ind = 0;
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
            break;
        }
    }
    if(cur == -1 && forward)
    {
        return 1;
    }
    else if(cur == n && !forward)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
 
int main()
{
    cin >> n >> q;
    cin >> s; 
    for(int i=1; i<=q; i++)
    {
        cin >> a[i] >> b[i];
    }
    int low = 0, high = n-1, mid;
    int forwardAns = -1;
    while(low <= high)
    {
        mid = (low + high)/2;
        // cout << "mid " << mid << endl;
        if(binarySearch(mid, 1))
        {
            low = mid + 1;
            forwardAns = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
 
    // cout << forwardAns << endl;
    low = 0, high = n-1;
    int backwardAns = n;
    while(low <= high)
    {
        mid = (low + high)/2;
        // cout << "mid " << mid << " " << low << " " << high << endl;
        if(binarySearch(mid, 0))
        {
            high = mid-1;
            backwardAns = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    // cout << backwardAns << endl;
    if(backwardAns <= forwardAns)
    {
        cout << n << endl;
    }
    else
    {
        cout << n - (forwardAns + 1 + (n-backwardAns)) << endl;
    }
    return 0;
}