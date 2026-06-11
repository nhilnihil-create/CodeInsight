#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    int a,j,ans,k=0;
    vector <int> m(55);
    rep(i,5555){
        a=10*(i+1)+1;
        j=2;
        ans=0;
        while(j*j<=a){
            if(a%j==0){
                ans=-1;
            }
            ++j;
        }
        if(ans==0){
            m[k]=a;
            if(k==54){
                break;
            }
            ++k;
        }
    }
    
    rep(i,n){
        cout << m[i] << " ";
    }
    

    return 0;
}