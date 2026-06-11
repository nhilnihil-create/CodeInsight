#include<bits/stdc++.h>
using namespace std;
#define in(a, n) for(int i=0;i<n;i++)
#define w while(t--)
#define tc int t; cin>>t;
int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}
bool sortbysec(const pair<string,long long> &a,
              const pair<string,long long> &b)
{
    return (a.second < b.second);
}
long long b[1000009];
long long z[1000009];
int lcm(int a, int b)
 {
    return (a*b)/__gcd(a, b);
 }
int main()
{
    int q[3];
    in(q,3) cin>>q[i];
    if(q[0]-q[1]==0)
        cout<<q[2];
    else if(q[0]-q[2]==0)
        cout<<q[1];
    else
        cout<<q[0];

}
