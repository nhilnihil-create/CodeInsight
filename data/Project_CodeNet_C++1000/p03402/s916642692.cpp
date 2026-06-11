#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

char s[102][102];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=50;i++)
        for(int j=1;j<=100;j++) s[i][j]='.';

    for(int i=51;i<=100;i++) {
        for(int j=1;j<=100;j++) {
            s[i][j]='#';
        }
    }
    int x=1,y=2;
    for(int i=1;i<m;i++) {
        s[x][y]='#';
        if(y==100) x+=2,y=0;
        y+=2;

    }
    x=100,y=2;
    for(int i=1;i<n;i++){
        s[x][y]='.';
        if(y==100) x-=2,y=0;
        y+=2;
    }
    cout<<100<<" "<<100<<endl;

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++)
             cout<<s[i][j];
        cout<<endl;
    }
    return 0;
}
