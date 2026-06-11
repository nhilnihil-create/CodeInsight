#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){
    ll i;
    vector<int> ans;
    cin>>i;
    if(i==0||i==1){
        cout<<i<<endl;
        return 0;
    }
    ll j=1;
    while(i!=0){
        ll i0=i;
        if(i0%(-2*j)==0){
            ans.push_back(0);
        }else{
            ans.push_back(1);
            i -= j;
        }
        j *=(-2);
    }
    for(auto ite=ans.end()-1;ite>=ans.begin();ite--){
        cout<<*ite;
    }
    cout<<endl;

    return 0;
}
