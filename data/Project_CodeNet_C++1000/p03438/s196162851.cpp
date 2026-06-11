#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);

    long long suma=0;
    long long sumb=0;

    for(int i=0;i<N;++i)
    {
        cin >> a[i];
    }

    for(int i=0;i<N;++i)
    {
        cin >> b[i];
    }

    long long step = 0;
    for(int i=0;i<N;++i)
    {
        if (a[i]%2 != b[i]%2)
        {
            b[i]++;
            step++;
        }
        if (a[i]>b[i])
        {
            step += a[i]-b[i];
        }
        else
        {
            step -= (b[i]-a[i])/2;
        }
    }
  
    if (step > 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}
