#include<iostream>
#define MOD 1000000007LL
using namespace std;
long long n,rez,i,A[100005],Dp[100005],val;

long long p(long long a, long long b)
{
    long long i,rez=1LL;
    for(i=0; (1LL<<i)<=b; i++)
    {
        if((1<<i)&b)
            rez=(rez*a)%MOD;
        a=(a*a)%MOD;
    }
    return rez;
}

int main()
{
    ios::sync_with_stdio(false);
    //Dp[i]=nr de permutari in care, pentru o secventa de lungime i,
    //elementul curent este primul eliminat
    //Dp[i]=n!/i. Dem. cu prob veizi solutia oficiala
    //Dem cu comb: x-nr de elemente care nu apar in intervalul de lg i, x=n-i
    //Dp[i]=n*(n-1)*(n-2)*...*(n-x+1)*(n-x-1)*(n-x-2)*(n-x-3)*...*2*1=n!/i
    //rezultatul e Dp[1...i]+Dp[2...n-i]
    //deoarece nr de premutari in care el i e legat de un element j, si elementul j se sterge
    //este egal cu Dp[j-i+1]
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>A[i];
    val=1;
    for(i=1; i<=n; i++)
        val=(val*i)%MOD;
    for(i=1; i<=n; i++)
        Dp[i]=(val*p(i,MOD-2))%MOD;
    for(i=1; i<=n; i++)
        Dp[i]=(Dp[i-1]+Dp[i])%MOD;
    for(i=1; i<=n; i++)
        rez=(rez+(A[i]*((Dp[i]+Dp[n-i+1]-Dp[1]+MOD)%MOD))%MOD)%MOD;
    cout<<rez<<"\n";
    return 0;
}
