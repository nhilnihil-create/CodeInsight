//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    if(n==3) cout<<"2 5 63"<<endl;
    else if(n==4) cout<<"2 4 3 9"<<endl;
    else{
        n-=4;
        cout<<"2 4 3 9 ";
        rep(i,4999){
            if(n==0) break;
            if(n==1){
                cout<<6<<endl;
                n--;
                break;
            }
            if(n==2) cout<<6*i+8<<" "<<6*i+10<<endl;
            else cout<<6*i+8<<" "<<6*i+10<<" ";
            n-=2;
        }
        rep(i,2499){
            if(n==0) break;
            if(n==1){
                cout<<6<<endl;
                n--;
                break;
            }
            if(n==2) cout<<12*i+15<<" "<<12*i+21<<endl;
            else cout<<12*i+15<<" "<<12*i+21<<" ";
            n-=2;
        }
        rep(i,5000){
            if(n==0) break;
            if(n==1) cout<<6*i+6<<endl;
            else cout<<6*i+6<<" ";
            n--;
        }
    }
}