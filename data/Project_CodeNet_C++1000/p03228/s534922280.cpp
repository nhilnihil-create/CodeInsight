#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int a,b,k;cin>>a>>b>>k;
    REP(i,k)
    {
        if (i%2==0&&a%2==0)
        {
            /* code */
            b+=a/2;
            a-=a/2;
        }
        else if(i%2==0&&a%2==1)
        {
            a-=1;
            b+=a/2;
            a-=a/2;
        }
        else if(i%2==1&&b%2==0)
        {
            a+=b/2;
            b-=b/2;

        }
        else if(i%2==1&&b%2==1)
        {
            b-=1;
            a+=b/2;
            b-=b/2;
        }
        
    }
    cout<<a<<' '<<b<<endl;

    }