#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    for (int i=0; i<N; i++)
    {
        cin >> B.at(i);
    }
    int test=A.at(0);
    for(int i=0; i<N; i++)
    {
        test+=B.at(i);
    }
    int max=test;
    for(int i=0; i<N-1; i++)
    {
        test=test-B.at(i)+A.at(i+1);
        if(test>max)
        {
            max=test;
        }
    }
    cout << max << endl;
}