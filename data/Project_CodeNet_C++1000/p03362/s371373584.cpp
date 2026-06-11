#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
    int n = 55556;
    vector <int> vect;
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n) 
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if(is_prime[i] == true && i%5 == 1)
        {
            vect.push_back(i);
        }
    }
    int m = 0;
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cout<<vect[i]<<" ";
    }

}
