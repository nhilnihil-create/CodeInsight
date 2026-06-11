#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX_V 100001
#define MOD 1000000007
typedef vector<vector<int> > Graph;

int main(){
    int n;cin>>n;
    int flag=1;
    int idx=0;
    int now=0;
    vector<int> b(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>b[i];

    while(flag==1&&b.size()>0){
        now=b[0];
        if(b.size()==1){
            if(now==1) ans[idx]=1;
            else flag=0;
            break;
        }
        for(int j=b.size()-1;j>0;j--){
            int c=b[j];
            if(c==j+1){
                ans[idx]=c;
                auto it=b.begin() + j;
                b.erase(it);
                break;
            }
            if(j==1&&now==1){
                ans[idx]=1;
                b.erase(b.begin());
            }
            else if(j==1&&now!=1) flag=0;
        }
        idx++;
    }

    if(flag==1){
        for(int i=n-1;i>=0;i--) cout<<ans[i]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
 

