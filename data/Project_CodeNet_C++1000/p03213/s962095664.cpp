#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    vector <int> so(50,1);
    int k;
    so[0]=0;
    so[1]=0;
    rep(i,25){
        k=2;
        if(so[i+2]==1){
        while(k*(i+2)<49){
            so[k*(i+2)]=0;
            ++k;
        }
        }
    }

    int n,s;
    cin >> n;
    vector <int> nn(50,0);
    rep(i,n){
        k=2;
        s=i+1;
        while(s!=1){
            while(s%k==0){
                s/=k;;
                ++nn[k];
            }
            ++k;
        }
    }

    

    int y2=0,y4=0,y14=0,y24=0,y74=0;
    rep(i,50){
        if(nn[i]>=2){
            ++y2;
        }
        if(nn[i]>=4){
            ++y4;
        }
        if(nn[i]>=14){
            ++y14;
        }
        if(nn[i]>=24){
            ++y24;
        }
        if(nn[i]>=74){
            ++y74;
        }
        //cout << i << " " << nn[i] << endl;
    }

    ll ans=0;
    ans+=y24*(y2-1);
    ans+=y14*(y4-1);
    ans+=(y4*(y4-1)/2)*(y2-2);
    ans+=y74;

    cout << ans << endl;
    

    

    return 0;
}