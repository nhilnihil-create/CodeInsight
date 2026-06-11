#include<iostream>
using namespace std;
int main()
{

    char a[4];
    int sum=700;
    cin>>a;

    for(int i=0; i<3; i++){
        if(a[i]=='o') sum+=100;
    }

    cout<<sum<<endl;

    return 0;
}

