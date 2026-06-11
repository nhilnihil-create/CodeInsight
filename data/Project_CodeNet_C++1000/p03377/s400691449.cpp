


#include <iostream>

using namespace std;

int main()
{int a,b,x;
cin>>a>>b>>x;
if(a>x){
    cout<<"NO";
}
else if((a+b)<x){
    cout<<"NO";
}
else if((a+b)>x &&a<=x){
    cout<<"YES";
}
    return 0;
}



