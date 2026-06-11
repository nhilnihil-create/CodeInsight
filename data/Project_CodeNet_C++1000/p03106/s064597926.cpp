#include<iostream>
using namespace std;
long long  arr[100000];
long long  arr2[100000];
int main()
{
    long long a=0,b=0,k=0,j=1;
    cin>>a>>b>>k;
    //if(a==1&&b==1&&k==1)
      //  cout<<"1"<<endl;
//    else
    {
        for(int i=max(a,b); i>=1; i--)
        {
            if(a%i==0&&b%i==0)
            {
                arr[j]=i;
                j++;
            }
        }
        cout<<arr[k]<<endl;
    }

    return 0;
}
