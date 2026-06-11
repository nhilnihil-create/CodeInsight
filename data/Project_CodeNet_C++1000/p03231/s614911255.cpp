# include <iostream>
using namespace std;

long long N, M;
string S;
string T;

long long gcd (long long a, long long b)
{
    if (b==0)
    {
        return a;
    }

    else
    {
        return gcd(b, a%b);
    }
}

long long lcm (long long a, long long b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    cin>>N>>M;
    cin>>S;
    cin>>T;
    
    long long L=lcm(N,M);
    long long g=gcd(N,M);

    for (int i=0; i<g; i++)
    {
        if (S[i*N/g]!=T[i*M/g])
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    cout<<L<<endl;
}