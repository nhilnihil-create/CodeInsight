#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prime;
    vector<bool> is_prime(100010, true);

    for (int i = 0; i < 2; i++)
    {
        is_prime[i] = false;
    }
    
    for (int i = 2; i <= 100000; i++)
    {
        if(is_prime[i])
        {
            for (int j = i * 2; j <= 100000; j += i)
            {
                is_prime[j] = false;
            }
            prime.push_back(i);
        }
    }
    
    vector<int> like2017(100010, 0);
    for (int i = 0; i < (int)prime.size(); i++)
    {
        if(is_prime[(prime[i] + 1) / 2])
        {
            like2017[prime[i]] = 1;
        }
    }
    vector<int> sumlike2017(100010, 0);
    for (int i = 0; i < 100010; i++)
    {
        sumlike2017[i + 1] = sumlike2017[i] + like2017[i + 1];
        //cout << sumlike2017[i] << " ";
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << sumlike2017[r] - sumlike2017[l - 1] << endl;
    }
    
}