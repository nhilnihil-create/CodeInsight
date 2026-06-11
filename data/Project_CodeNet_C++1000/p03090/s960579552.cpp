#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int sum= (n*(n+1))>>1;
    if(!(sum&1))
    {
        vector<int>v1, v2;
        sum/= 2;
        for(int i=n; i>=1; i--)
        {
            if(sum>=i)v1.push_back(i), sum-= i;
            else v2.push_back(i);
        }
        printf("%d\n", v1.size()*v2.size());
        for(int i=0; i<v1.size(); i++)
        {
            int x= v1[i];
            for(int j=0; j<v2.size(); j++)
            {
                int y= v2[j];
                printf("%d %d\n", x, y);
            }
        }
    }
    else
    {
        vector<int>vec[102];
        int cnt= 0;

        for(int i=1, j=n-(n%2); i<=n/2; i++, j--)
        vec[++cnt].push_back(i), vec[cnt].push_back(j);
        if(n&1)vec[++cnt].push_back(n);

        int res= 0;
        for(int i=1; i<cnt; i++)
        res+= vec[i].size()*vec[i+1].size();
        res+= vec[cnt].size()*vec[1].size();
        printf("%d\n", res);

        for(int i=1; i<cnt; i++)
        for(int j=0; j<vec[i].size(); j++)
        {
            int x= vec[i][j];
            for(int k=0; k<vec[i+1].size(); k++)
            {
                int y= vec[i+1][k];
                printf("%d %d\n", x, y);
            }
        }
        for(int j=0; j<vec[cnt].size(); j++)
        {
            int x= vec[cnt][j];
            for(int k=0; k<vec[1].size(); k++)
            {
                int y= vec[1][k];
                printf("%d %d\n", x, y);
            }
        }
    }
    return 0;
}
