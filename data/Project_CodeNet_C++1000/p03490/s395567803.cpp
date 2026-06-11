#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> fx(16010);
    vector<int> fy(16010);
    vector<int> dx;
    vector<int> dy;    
    int i;
    int sc = 0;
    for(i = 0; i < s.size(); i++)
    {
        while(s[i] != 'T' && i < s.size())
        {
            sc++;
            i++;
        }
        break;
    }
    fx[8000+sc] = 1;
    fy[8000] = 1;

    int tc = 0;
    for(int j = i; j < s.size();)
    {
        int fc = 0;
        while(s[j] == 'T' && j < s.size())
        {
            tc++;
            j++;
        }
        while(s[j] == 'F' && j < s.size())
        {
            fc++;
            j++;
        }
        if(tc % 2 == 1)
        {
            dy.push_back(fc);
        }
        else
        {
            dx.push_back(fc);
        }
    } 
 
    // x
    for(int i = 0; i < dx.size(); i++)
    {
        for(int j = 0; j < 16010; j++)
        {
            if(fx[j] == i+1)
            {
                fx[j] = 0;
                int k = j;
                while(fx[k-dx[i]] == i+1)
                {
                    fx[k-dx[i]] = i+2;
                    k -= dx[i];
                }
                fx[k-dx[i]] = i+2;
                while(fx[k+dx[i]] == i+1)
                {
                    fx[k+dx[i]] = i+2;
                    k += dx[i];
                }
                fx[k+dx[i]] = i+2;
            }
        }
    }
    // y
    for(int i = 0; i < dy.size(); i++)
    {
        for(int j = 0; j < 16010; j++)
        {
            if(fy[j] == i+1)
            {
                fy[j] = 0;
                int k = j;
                while(fy[k-dy[i]] == i+1)
                {
                    fy[k-dy[i]] = i+2;
                    k -= dy[i];
                }
                fy[k-dy[i]] = i+2;
                while(fy[k+dy[i]] == i+1)
                {
                    fy[k+dy[i]] = i+2;
                    k += dy[i];
                }
                fy[k+dy[i]] = i+2;
            }
        }
    }
    if(fx[8000+x] == dx.size() + 1 && fy[8000+y] == dy.size() + 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
