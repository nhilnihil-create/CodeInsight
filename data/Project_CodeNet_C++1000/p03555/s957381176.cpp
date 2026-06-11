#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c1,c2,c3,c4,c5,c6;
    cin>>c1>>c2>>c3>>c4>>c5>>c6;
    int flag=1;
    if(c1!=c6){
        flag=0;
    }
    if(c2!=c5){
        flag=0;
    }
    if(c3!=c4){
        flag=0;
    }
    if(flag==0){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}
