#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    string p,y="YYMM",a="AMBIGUOUS",m="MMYY",n="NA";
    cin>>p;
    p[0]=p[0]-'0';
    p[1]=p[1]-'0';
    p[2]=p[2]-'0';
    p[3]=p[3]-'0';
    if(((p[2]==0&&p[3]>=1&&p[3]<=9)||(p[2]==1&&(p[3]==0||p[3]==1||p[3]==2)))&&((p[0]==0&&p[1]>=1&&p[1]<=9)||(p[0]==1&&(p[1]==0||p[1]==1||p[1]==2))))
    cout<<a;
    else if((p[0]==0&&p[1]>=1&&p[1]<=9)||(p[0]==1&&(p[1]==0||p[1]==1||p[1]==2)))
      cout<<m;
    else if((p[2]==0&&p[3]>=1&&p[3]<=9)||(p[2]==1&&(p[3]==0||p[3]==1||p[3]==2)))
      cout<<y;
    else
      cout<<n;
    nl;
    return 0;
}
