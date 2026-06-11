#include<iostream>
using namespace std;
int main()
{
    int n,i,k;
    char str[50];
    cin>>n; cin>>k;
    for(i=1;i<=n;i++){
        cin>>str[i];

    }

    str[k]=tolower(str[k]);
    for(i=1;i<=n;i++){
       cout<<str[i];
    }
}
