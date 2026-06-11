#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, H;
    cin >> N >> H;
    int a[N], b[N];

    int max_A=0;
    for(int i=0;i<N;i++)
    {
        cin >> a[i] >> b[i];
        max_A=max(a[i], max_A);
    }
    sort(b, b+N, greater<int>());

   long long int sum=0, counter=0;
   long long int ans=0;
    for(int i=0;i<N;i++)
    {
        if(b[i]>max_A)
        {
            sum=sum+b[i];
            counter++;
            if(sum>=H)
            {
                break;
            }
        }

        else
        {
            break;
        }
    }
    ans=counter;
    H=H-sum;

    if(H>0)
    {
    if(H%max_A==0)
    {
        ans=ans+H/max_A;
    }

    else
    {
        ans=ans+(H/max_A)+1;
    }
    }
    cout << ans;
}
