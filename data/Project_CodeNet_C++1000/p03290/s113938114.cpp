#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){

    int D,G;
    cin>>D>>G;
    ll p[D],c[D];
    int sum=0;
    int ans;
    int min_ans=10000;

    for(int i=0;i<D;i++){
        cin>>p[i]>>c[i];
    }
    for(int i=0;i<(int)pow(2,D);i++){
        sum=0;
        ans=0;
        for(int j=0;j<D;j++){
            if(i&(1<<j)){
                sum+=(j+1)*100*p[j]+c[j];
                ans+=p[j];
            }
        }
        if(sum<G){
            for(int j=D-1;j>=0;j--){
                if(!(i&(1<<j))){
                    for(int k=0;k<p[j];k++){
                        if(sum>=G){
                            break;
                        }
                        ans++;
                        sum+=(j+1)*100;
                    }
                }
            }
        }
        if(sum>=G&&ans<min_ans){
            min_ans=ans;
        }
    }
    cout<<min_ans<<endl;
    return 0;
}
