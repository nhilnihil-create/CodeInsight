#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    string s;
    int sum=0;
    cin>>s;

    for(int i=0; i<4; i++){
        if(s[i]=='+') sum++;
        else sum--;
    }

    cout<<sum<<endl;

    return 0;
}

