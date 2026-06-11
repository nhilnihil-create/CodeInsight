#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long> a(N);
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    
    long ans1 = a[0];
    
    long ans2 = a[1];
    
    long temp = LONG_MAX;
    
    if(a[0] %2 == 1)
    {
        long ref1 = a[0]/2;
        long ref2 = a[0]/2+1;
        for(int i = 1;i<N;i++)
        {
            if(min(abs(a[i]-ref1),abs(a[i]-ref2)) < temp)
            {
                temp = min(abs(a[i]-ref1),abs(a[i]-ref2));
                ans2 = a[i];
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        long ref = a[0]/2;
        for(int i=1;i<N;i++)
        {
        if(abs(a[i]-ref) < temp)
        {
            temp = abs(a[i]-ref);
            ans2 = a[i];
        }
        else
        {
            break;
        }
        }
    }
    
    cout << ans1 << " " << ans2 << endl;
    return 0;
    
}


 