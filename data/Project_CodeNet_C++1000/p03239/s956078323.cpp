#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b[1007],c[1007],e,d[1007],f,t,i,j,k=0;
    cin>>t>>a;
    for(i=0;i<t;i++){
        cin>>b[i]>>c[i];
        if(c[i]<=a){
            d[k]=b[i];
            k++;}}
            sort(d,d+k);
            if(k==0)
                cout<<"TLE"<<endl;
            else
            cout<<d[0]<<endl;
            return 0;}


