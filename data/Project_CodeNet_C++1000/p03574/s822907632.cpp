#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define ws(x) scanf("%d",&x);getchar();while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int N=1e6+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i;
string s[55],ch;

int main()
{
    cin>>a>>b;
    cin.ignore();
    s[0]=(b,'0');
    for(i=1;i<=a;i++){
        cin>>ch;
        s[i]='0'+ch;
    }
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            n=0;
            if(s[i][j]=='#'){
                continue;
            }
            if(s[i][j+1]=='#') n++;
            if(s[i][j-1]=='#') n++;
            if(s[i+1][j]=='#') n++;
            if(s[i-1][j]=='#') n++;
            if(s[i-1][j-1]=='#') n++;
            if(s[i-1][j+1]=='#') n++;
            if(s[i+1][j-1]=='#') n++;
            if(s[i+1][j+1]=='#') n++;
            s[i][j]=char(n+'0');
        }
    }
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++)
            cout<<s[i][j];
        cout<<endl;
    }
}

