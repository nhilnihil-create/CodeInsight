#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

vector<int>ve0,ve1,ve2;
int p[502][502];
int n,c;

void floyd()
{

    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            for(int r=1;r<=c;r++){
                p[j][r]=min(p[j][r],p[j][i]+p[i][r]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
     cin>>n>>c;
     for(int i=1;i<=c;i++) {
            for(int j=1;j<=c;j++)
        cin>>p[i][j];
     }
    //floyd();
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            if((i+j)%3==0) ve0.push_back(x);
            else if((i+j)%3==1) ve1.push_back(x);
            else ve2.push_back(x);
        }
     }
     ll sum=0,sum1=0,sum2=0,ans=1e9;

     for(int i=1;i<=c;i++){
            sum=0;
            for(auto v:ve0){
                sum+=p[v][i];
            }
        for(int j=1;j<=c;j++){
                sum1=0;
                if(j==i) continue;
                for(auto v:ve1){
                    sum1+=p[v][j];
                }
            for (int r=1;r<=c;r++){
                    sum2=0;
                if(r==i || r==j) continue;
                for(auto v:ve2){
                    sum2+=p[v][r];
                }
//                cout<<i<<" "<<j<<":"<<r<<endl;
//                cout<<sum<<" "<<sum1<<" "<<sum2<<endl;
                //if(sum==0 || sum1==0 || sum2==0) continue;
                ans=min(ans,sum+sum1+sum2);
            }

        }

     }
     cout<<ans<<endl;
    return 0;
}
