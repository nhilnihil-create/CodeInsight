#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int a,b,k;
        cin>>a>>b>>k;
        int maxn=max(a,b);
        int n=0;
        for(int i=maxn;i>=1;i--)
        {
                if(a%i==0&&b%i==0)
                        n++;
                if(n==k){
                        cout<<i<<endl;
                        break;
                }
        }
        return 0;
}
