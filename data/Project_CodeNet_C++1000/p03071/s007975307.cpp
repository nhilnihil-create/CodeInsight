#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int c=max(a,b);
    int d=min(a,b);
    if(c-2>=d){\
        cout<<c+c-1<<endl;
    }else{
        cout<<c+d;
    }

}
