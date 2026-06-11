#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,i=0,s=1,j,m;
    cin >> n;
    string str[n];
    for (i=0;i<n;i++)
        cin >> str[i];
    m=i=1;
    while (m<=n)
    {
        if (str[i][0]==str[i-1][str[i-1].size()-1])
            i++;
        m++;
    }
    if (i+1!=m)
    {
        cout << "No";
        return 0;
    }
    else
    {
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                if (str[i]==str[j])
                    s=-1;
    }
    if (s==-1)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
