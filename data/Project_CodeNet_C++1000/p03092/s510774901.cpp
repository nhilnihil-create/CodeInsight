#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    long long A, B;
    cin>>A>>B;

    vector<int> p(N);
    for (int &t: p)
    {
        cin>>t;
        t--;
    }

    vector<int> R(N);
    for (int i=0; i<N; i++)
        R[p[i]] = i;

    vector<long long> T(2*N+1);
    for (int i=0; i<N; i++)
    {
        vector<long long> P = T;
        T = vector<long long>(2*N+1);
        for (int j=1; j<2*N+1; j++)
            P[j] = min(P[j], P[j-1]);
        for (int j=0; j<2*N+1; j++)
        {
            long long c;
            if (j<R[i]*2+1)
                c = B;
            else if (j>R[i]*2+1)
                c = A;
            else
                c = 0;
            T[j] = P[j/2*2]+c;
        }
    }

    cout<<*min_element(T.begin(), T.end())<<endl;
}
