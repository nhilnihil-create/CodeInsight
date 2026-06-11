#include<bits/stdc++.h>
using namespace std;
int main()
{

    char arr[1000];
    int w,c,i;
    scanf("%[^\n]s",&arr);
    cin>>w;
    c=strlen(arr);
    w=w-1;
    cout<<arr[0];
    for(i=1;i<c;i++)
    {
        if((i+w)>=c)
        {
            break;
        }
        else{
            cout<<arr[i+w];
        i=i+w;
        }

    }

    return 0;
}
