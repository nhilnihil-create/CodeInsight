#include<iostream>
using namespace std;

int main()
{

    int n, a;
    cin>>n>>a;

    int rem;

    rem= n%500;

    if(rem>a) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}
