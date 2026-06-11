#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    int count=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; ; j++)
        {
            if(A.at(i)%2==0)
            {
                A.at(i)=A.at(i)/2;
                count++;
            }
            else
            {
                break;
            }
        }
    }
    cout << count << endl;
}