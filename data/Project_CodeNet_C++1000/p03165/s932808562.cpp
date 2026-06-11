#include <bits/stdc++.h>
#define N 3500
using namespace std;
int mem[N][N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, w;
    vector <char> path;
    cin >> s >> w;
    memset(mem, 0, sizeof(mem));
    int m = s.size();
    int n = w.size();
    for(int i = m - 1;i >= 0;i--)
    {
        for(int j = n - 1;j >= 0;j--)
        {
            if(s[i] == w[j])
            {
                mem[i][j] = 1 + mem[i + 1][j + 1];
            }
            else
            {
                int a= mem[i+1][j];
                int b = mem[i][j + 1];
                mem[i][j] = max(a , b);
            }
        }
    }
    if(mem[0][0] != 0){
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int a = mem[i+1][j];
            int b = mem[i][j+1];
            int c = max(a, b);
            if(c == mem[i][j])
            {
                if(mem[i][j] == a)
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                path.push_back(s[i]);
                if(path.size() == mem[0][0])
                    break;
                i++;
                continue;
            }
        }
        if(path.size() == mem[0][0])
            break;
    }
    if(path.empty() != 1)
        for(int i = 0;i < path.size();i++)
            cout << path[i];
    if(path.empty() != 1)
        cout << endl;}
    return 0;
}