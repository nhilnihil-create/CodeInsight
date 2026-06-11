#include <bits/stdc++.h>
using namespace std;
#define ref(i,n) for(int i =0;i<n;i++)

int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    int arr[n][m],emm[m];
    ref(i,m)
    cin>>emm[i];
    ref(i,n)
    {
        ref(j,m)
        {
            cin>>arr[i][j];
        }
    }
    int count = 0,temp=  0;
    ref(i,n)
    {   
        temp = 0;
        ref(j,m)
        {
           temp += arr[i][j]*emm[j];
        }
        if(temp+c > 0)
            ++count;
    }
    cout<<count<<endl;
    return 0;
}