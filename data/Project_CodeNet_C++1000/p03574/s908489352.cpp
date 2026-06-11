#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int h,w;
int a[55][55];
char s;
int ans;
int main(void){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>s;
            if(s=='#'){
                a[i][j]=1;
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j]==1){
                cout<<'#';
            }else{
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        ans+=a[i+k][j+l];
                    }
                }
                cout<<ans;
                ans=0;
            }
        }
        cout<<endl;
    }

}
