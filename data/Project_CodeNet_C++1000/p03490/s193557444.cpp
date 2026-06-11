#include<bits/stdc++.h>
using namespace std;
#define con continue
#define bk break
#define LL long long
#define db double
#define pt cout<<'\n'
#define ms(a, b) memset((a), (b), sizeof(a))
#define mp make_pair
#define endl '\n'
LL inf=2147483647;const long long ll =9223372036854775807,ninf=1000000000;const double eps = 1e-6; const long long nll =1000000000000000000;
#define sz size()
#define len(X) strlen(X)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ULL unsigned long long
#define de cout<<"test"<<endl;
#define st system("pause");
#define F first
#define S second
class MagicNumberThree
{

    public:
int countSubsequences(string s)
{

}

};

int dp[2][45005]={};
int tmp[2][45005]={};
int main()
{
    string a;
    while(cin>>a){
            int x,y;
    cin>>x>>y;
            int now=0;
dp[1][8000]=1;
        int i;
        for(i;a[i]=='F';i++);

        dp[0][8000+i]=1;
        int cnt=0;
        for(i;i<=a.sz;i++){
            if(a[i]=='F'){
                cnt++;
            }
            else{
                for(int j=cnt;j<20000;j++){
                    tmp[now][j-cnt]=max(tmp[now][j-cnt],dp[now][j]);
                     tmp[now][j+cnt]=max(tmp[now][j+cnt],dp[now][j]);
                }
                for(int j=0;j<20000;j++){
                    dp[now][j]=tmp[now][j];
                }
                ms(tmp,0);
                cnt=0;
                now^=1;
            }

        }
        if(dp[0][x+8000]&&dp[1][y+8000]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }


    return 0;
}
