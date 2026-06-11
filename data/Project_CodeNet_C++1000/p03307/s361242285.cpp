#include<iostream>
using namespace std;
int main()
{
    int result;
    int N;
    while(cin>>N)
    {
        if(N%2==0)
            cout<<N<<endl;
        else
            cout<<2*N<<endl;
    }
  return 0;
}