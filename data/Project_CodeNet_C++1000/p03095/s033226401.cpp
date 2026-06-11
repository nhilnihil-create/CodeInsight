#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string a1;
    cin>>a1;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        a.at(i)=a1[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(26,0);
    int c=0;
    string d=a.at(0);
    for (int i = 0; i < n; i++)
    {
        if (a.at(i)==d)
        {
            b.at(c)++;
        }else
        {
            c+=1;
            b.at(c)++;
            d=a.at(i);
        }
        
        
    }
    int64_t e=1;
    for (int i = 0; i < 26; i++)
    {
        e=(e*(b.at(i)+1))%1000000007;
    }
    e--;
    cout<<e<<endl;

    

    



    return 0;
}