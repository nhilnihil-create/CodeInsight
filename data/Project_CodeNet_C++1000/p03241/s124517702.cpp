#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, M;
    cin >> N >> M;
    vector<long long> vec;

    for (long long i = 1; i <= (long long)pow(M, 0.5); i++)
    {
        if (M % i == 0)
        {  
            if (M / i <= M / N)
            {
                long long ans = M / i;
                cout << ans << endl;
                exit(0);
            }
            else
            {
                vec.push_back(i);
            }                
        }
    }
    for (long long i = 0; i < vec.size(); i++)
    {
        if (vec[i] > M / N)
        {
            cout << vec[i-1] << endl;
            exit(0);
        }
    }
    cout << vec[vec.size()-1] << endl;
}