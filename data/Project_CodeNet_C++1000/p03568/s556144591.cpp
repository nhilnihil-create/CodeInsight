#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin >> A.at(i);
    }

    int ans = 1;
    for(int i=0;i<N;i++)
    {
        ans *= 3;
    }
    int mai = 1;
    for(int i=0;i<N;i++)
    {
        if(A.at(i)%2==0)
        {
            mai *= 2;
        }
    }

    cout << ans - mai << endl;

    return 0;
}