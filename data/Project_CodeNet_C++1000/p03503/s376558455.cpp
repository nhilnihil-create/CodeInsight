#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> data(N);
    vector<vector<long>> value(N);
    
    for(int i=0;i<N;i++)
    {
        for(int j = 0;j<10;j++)
        {
            int t;
            cin >> t;
            data[i].push_back(t);
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j = 0;j<11;j++)
        {
            long t;
            cin >> t;
            value[i].push_back(t);
        }
    }
    
    long ans = LONG_MIN;
    
    
    
    for(int i = 0;i<(1<<10);i++) //1024
    {
        long tx = 0;
        bool nouse = true;
        bitset<10> temp(i);
        vector<int> used(N,0);
        for(int j = 0;j<10;j++)
        {
            if(temp[j] == 1)
            {
                nouse = false;
                for(int k = 0;k<N;k++)
                {
                    if(data[k][j] == 1)
                    {
                        used[k] ++;
                    }
                }
            }
        }
        
        for(int k = 0;k<N;k++)
        {
            tx += value[k][used[k]];
        }
        if(!nouse)
        {
            ans = max(ans,tx);
        }
        
    }
    
    
    
    cout << ans << endl;
    return 0;
    
}