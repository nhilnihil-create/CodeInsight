# include <iostream>
using namespace std;

long long A;
long long B;
long long C;

int main()
{
    cin>>A>>B>>C;

    if (A+B>=C)
    {
        cout<<B+C<<endl;
    }

    else
    {
        cout<<A+2*B+1<<endl;
    }
}