/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx=8e3+5;
int X[2];
char str[mx];
vector <int> ara[2];
int8_t DP[2*mx][mx][2];

int8_t solve (int x,int pos,int i)
{
    if (pos==ara[i].size()) {///cout<<pos<<endl;
        if (x==X[i]) return DP[x+mx][pos][i]=1;
        else return DP[x+mx][pos][i]=-1;
    }
    if (DP[x+mx][pos][i]!=0) return DP[x+mx][pos][i];
    return DP[x+mx][pos][i]=max(solve(x+ara[i][pos],pos+1,i),solve(x-ara[i][pos],pos+1,i));
}

int main ()
{
    int i,n;

    scanf ("%s",str);
    scanf ("%d %d",&X[0],&X[1]);
    n=strlen(str);
    int j=0,cnt=0;
    for (i=0;i<n;i++) {
        if (str[i]=='T') {
            ara[j].push_back(cnt);
            cnt=0;
            j^=1;
        }
        else cnt++;
    }
    ara[j].push_back(cnt);
    int rx=solve(ara[0][0],1,0);
    int ry=solve(0,0,1);///cout<<rx<<' '<<ry<<endl;
    if (rx==1 && ry==1) printf ("Yes\n");
    else printf ("No\n");

    return 0;
}
