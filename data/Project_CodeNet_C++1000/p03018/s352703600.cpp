#include<bits/stdc++.h>
#define fr(i,j,n) for(int i=j;i<n;i++)
#define pb        push_back
#define rf(i,j,n) for(i=n;i>=j;i--)
#define vi        vector<int>
#define hmm        "\n"
#define sp        " "
using namespace std;
int main()
{
    string p ;
    cin >> p;
    long long  ac = 0,ans=0;
    fr(i,0,p.size())
    {
        if(p[i]=='A'){ac++;}
        else if(i+1<p.size() && p[i]=='B' && p[i+1]=='C'){
            ans+=ac; i++;
        }
        else {ac=0;}
    }
    cout<<ans<<hmm;
}
