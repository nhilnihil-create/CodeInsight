#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5],b=0,c,k;

    for(int i=0; i<3; i++ ){
        cin>>a[i];
    }

    for(int i=0; i<3; i++ ){
        if(a[i]>=b){
            b=a[i];
            c=i;
        }
    }
    cin>>k;
    for(int i=0; i<k; i++ ){
        b*=2;
    }
    a[c]=b;
    cout<<a[0]+a[1]+a[2]<<endl;
    return 0;

}
