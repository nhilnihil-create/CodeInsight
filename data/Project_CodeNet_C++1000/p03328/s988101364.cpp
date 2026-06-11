#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,k1=0,k2=0;
    cin>>a>>b;
    for(int i=1; ;i++){
        k1=(i*(i+1))/2;
        k2=((i+1)*(i+1+1))/2;
        if(k1>=a && k2>=b && (k1-a)==(k2-b)) break;
    }
    cout<<k1-a;
    return 0;
}
