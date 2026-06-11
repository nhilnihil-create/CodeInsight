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
class MinimizeAbsoluteDifferenceDiv1
{
    public:
vector <int> findTuple(vector <int> x)
{


}
};
int main()
{
    LL a,b;
    while(cin>>a>>b){
        LL w[100005]={};
        LL w1[100005]={};
        LL w2[100005]={};
        LL x[100005]={};
        for(int i=1;i<=a;i++){
            cin>>x[i]>>w[i];
        }
        for(int i=1;i<=a;i++)
            w[i]=w[i-1]+w[i];

        LL t1[100005]={};
        LL t2[100005]={};
        LL ans=0;
        for(int i=1;i<=a;i++){
            w1[i]=w[i]-x[i];
            w2[i]=w[a]-w[i-1]-(b-x[i]);
            t1[i]=w1[i]-x[i];

            t2[i]=w2[i]-(b-x[i]);

            ans=max(ans,w1[i]);
            ans=max(ans,w2[i]);
        }
        LL num=0;
        for(int i=1;i<=a;i++){
            ans=max(ans,num+w2[i]);
            num=max(num,t1[i]);
        }
        num=0;
        for(int i=a;i>=1;i--){
                   ans=max(ans,num+w1[i]);
            num=max(num,t2[i]);

        }
        cout<<ans<<endl;
    }
    return 0;
}
