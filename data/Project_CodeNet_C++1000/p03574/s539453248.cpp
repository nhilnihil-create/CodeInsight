#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{
int n ,m;
cin>>n>>m;
cin.ignore();
char s[n][m];
for(int index = 0 ;index <n ;index++)
    for(int j = 0 ; j< m ;j++)
    cin>>s[index][j];


    for(int  i= 0 ; i< n ; i++)
    {
        for(int j= 0; j<m;j++)
        {
            if(s[i][j]=='.')
            {
                int ans = 0;
                if(j+1<m&&s[i][j+1]=='#')ans++;
                if(j-1>=0&&s[i][j-1]=='#')ans++;

                if(i-1>=0)
                {
                    if(s[i-1][j]=='#')ans++;
                    if(j+1<m&&s[i-1][j+1]=='#')ans++;
                    if(j-1>=0&&s[i-1][j-1]=='#')ans++;
                }

                if(i+1<n)
                {
                    if(s[i+1][j]=='#')ans++;
                    if(j+1<m&&s[i+1][j+1]=='#')ans++;
                    if(j-1>=0&&s[i+1][j-1]=='#')ans++;
                }
                cout<<ans;
            }
            else
                cout<<"#";
        }
        cout<<endl;
    }
 return 0;
}
