#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int main()
{
    int n;
    string s;
    in n>>s;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int check=0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            bool left=false,right=false;
            for (int j = 0; j < i; j++)
            {
                if(s[j]==c)left=true;
            }

            for(int j=i;j<n;j++)
            {
                if(s[j]==c)right=true;
            }
            if(left&&right)check++;
        }
        if(ans<check)ans=check;
    }
    cout<<ans<<endl;
}
