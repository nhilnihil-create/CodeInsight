#include <bits/stdc++.h>

using namespace std;

int main()
{
 int r,D,xi,xf;
 cin>>r>>D>>xi;
 if(r>=2&&r<=5&&D<=100&&D>=1&&xi>D&&xi<=200){
     for (int j=1;j<11;j++){
        xf=(r*xi)-D;
        xi=xf;
        cout<<xf<<endl;
     }
     
 }
    return 0;
}