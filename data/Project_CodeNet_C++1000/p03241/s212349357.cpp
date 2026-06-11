#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    int ans;
    if (M % N == 0)
    {
        ans = M / N;
    }else
    {
        vector<int> div;
        for (int i = 1; i * i <= M; i++)
        {
            if (M % i == 0)
            {
                div.emplace_back(i);
                div.emplace_back(M / i);
            }
            
        }
        sort(div.begin(), div.end());
        for (int a : div)
        {
            if (a >= N)
            {
                ans = M / a;
                break;
            }
            
        }
           
    }
    
    cout << ans << endl;
    
    return 0;
}