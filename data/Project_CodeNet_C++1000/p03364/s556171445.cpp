#include <iostream>
using namespace std;
char a[305][305],b[305][305];
int n,res=0;
string s[305];
bool check()
{
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            if (b[i][j]!=b[j][i]) return false;
    return true;
}
int main()
{
    cin>>n;

    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j];
    for (int p=0;p<n;++p)
    {
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                b[i][(j+p)%n]=a[i][j];
        if (check()) res+=n;
    }
    cout<<res;
    return 0;
}
