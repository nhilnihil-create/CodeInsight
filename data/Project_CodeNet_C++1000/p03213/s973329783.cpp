#include <bits/stdc++.h>
using namespace std;

//75 = 3 5 5 >> 18

//1 1 75
//1 3 25
//1 5 15
//3 5 5

int main()
{
    int N;
    cin >> N;
    
    vector<int> data(100,1);
    
    for(int i = 2;i<=N;i++)
    {
        int temp = i;
        for(int j = 2; j<=sqrt(temp);j++)
        {
            if(temp % j == 0)
            {
                temp /= j;
                data[j] ++;
                j = 1;
            }
        }
        
        data[temp]++;
    }
    
    vector<int> data3(100,0);
    vector<int> data5(100,0);
    vector<int> data15(100,0);
    vector<int> data25(100,0);
    vector<int> data75(100,0);
    
    for(int i = 2;i<=N;i++)
    {
        if(data[i] >= 3)
        {
            data3[i] = 1;
            if(data[i] >= 5)
            {
                data5[i] = 1;
                if(data[i] >= 15)
                {
                    data15[i] = 1;
                    if(data[i] >= 25)
                    {
                        data25[i] = 1;
                        if(data[i] >= 75)
                        {
                            data75[i] = 1;
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 2;i<=N;i++)
    {
        if(data75[i] == 1)
        {
            ans ++;
        }
        if(data25[i] == 1)
        {
            for(int j = 2;j<=N;j++)
            {
                if(data3[j] == 1 && j != i)
                {
                    ans ++;
                }
            }
        }
        if(data15[i] == 1)
        {
            for(int j = 2;j<=N;j++)
            {
                if(data5[j] == 1 && j != i)
                {
                    ans ++;
                }
            }
        }
        if(data5[i] == 1)
        {
            for(int j = i+1;j<=N;j++)
            {
                if(data5[j] == 1 && j != i)
                {
                    for(int k = 2;k<=N;k++)
                    {
                        if(data3[k] == 1 && k != i && k!= j)
                        {
                            ans ++;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    
    
    
    
    return 0;
    
}