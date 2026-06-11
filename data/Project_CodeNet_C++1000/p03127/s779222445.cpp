#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
        long long int n;
        cin >> n;
        long long int a[n];
        int i;
        for(i=0;i<n;i++)
                cin >> a[i];
        long long int x=0,y=0;
        long long int b[n];
        sort(a,a+n);
        x=a[0];
        int j;
        while(true)
        {
                int y=x;
                for(i=0;i<n;i++)
                {
                        if(a[i]%x==0);
                        else
                        {
                                a[i]=a[i]%x;
                                x=a[i]%x;
                        }
                }
                if(y==x)
                        break;
        }
        cout << x << "\n";
}
