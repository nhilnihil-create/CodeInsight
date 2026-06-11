
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
using namespace std;

const double pi = acos(-1);

#define nyan cout<<"(=^•ω•^=)"<<endl;
#define int long long

int n;
int ans[2000][2000];

int generate(){
    ans[0][0]=1;
    ans[0][1]=2;
    ans[1][0]=2;
    ans[1][1]=3;
    ans[2][0]=1;
    ans[2][1]=3;
    for(int i=3;i<=1000;i++){
        for(int k=(i-1)*i/2+1;k<=i*(i+1)/2;k++){
            ans[k-((i-1)*i/2+1)][i-1]=k;
            ans[i][k-((i-1)*i/2+1)]=k;
        }
    }
    return 0;
}

signed main(){
    generate();
    cin>>n;
    if(n==1){
        cout<<"Yes"<<endl;
        cout<<"2"<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    for(int i=1;i<=1000;i++){
        if(i*(i+1)/2>n){
            cout<<"No"<<endl;
            return 0;
        }
        if(i*(i+1)/2==n){
            cout<<"Yes"<<endl;
            i++;
            cout<<i<<endl;
            for(int k=0;k<i;k++){
                cout<<i-1<<" ";
                for(int m=0;m<i-1;m++){
                    if(m==i-2)cout<<ans[k][m]<<endl;
                    else cout<<ans[k][m]<<" ";
                }
            }
            return 0;
        }
    }
    return 0;
}