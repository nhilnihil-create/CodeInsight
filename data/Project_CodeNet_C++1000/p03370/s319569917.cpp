#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, X, m[200];
    cin >> N >> X;
    int sum = 0, M=1001001001;
    for (int i = 0; i < N; i++)
    {

        cin >> m[i];
        sum += m[i];
        if (m[i]<M)
        {
         M=m[i];
        }
    }
        int ans =N+(X-sum)/M;
        cout<< ans<<endl;
    
}