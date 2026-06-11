#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 

int  A(int x){
    if(x>=0)return x;
    else return -x;
}



int main(void){
    ll k;
    cin>>k;
    vector<ll>a(k);
    for(ll i=0;i<k;i++){
        cin>>a[i];
    }
    ll mi = 0,ma = 0;
    for(ll i=k-1;i>=0;i--){
        if(i==k-1){
            if(a[i]!=2){
                cout<<-1<<endl;
                return 0;
            }
            else{
                mi = 2;
                ma = 3;
            }
        }
        else{
            if(a[i]>ma){
                cout<<-1<<endl;
                return 0;
            }
            ll tmp1 = 0,tmp2 = 0;
            if(mi%a[i]==0){
                tmp1 = mi/a[i];
                tmp1 = a[i]*tmp1;
            }
            else{
                tmp1 = mi/a[i];
                tmp1 = (tmp1+1)*a[i];
            }
            tmp2 = ma/a[i];
            tmp2 = a[i]*tmp2;
            if(tmp1>tmp2){
                cout<<-1<<endl;
                return 0;
            }
            mi = tmp1;
            ma = a[i]*(tmp2/a[i]+1)-1;
        }
        //cout<<mi<<" "<<ma<<endl;
    }
    cout<<mi<<" "<<ma<<endl;
    return 0;
}