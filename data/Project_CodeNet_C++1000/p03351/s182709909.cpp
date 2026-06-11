#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
int a,b,c,d;
cin>>a>>b>>c>>d;
bool direct=false;
bool kansetu=false;
if (abs(a-b)<=d&&abs(b-c)<=d)
{
    /* code */
    kansetu=true;
}

if (abs(a-c)<=d)
{
    /* code */
    direct=true;
}

if (direct||kansetu)
{
    /* code */
    cout<<"Yes"<<endl;
}
else
{
    cout<<"No"<<endl;
}

}