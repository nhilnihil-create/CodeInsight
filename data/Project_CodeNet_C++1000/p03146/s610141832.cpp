#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef long double ld;



int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int s;
        cin>>s;
        vector<int> a(1000001);
        a.at(s)++;
        for(int i=2;i<=1000000;i++){
            int n;
            if(s%2==0){
                n=s/2;
            }
            else{
                n=(3*s)+1;
            }
            if(a.at(n)==1){
                cout<<i;
                return 0;
            }
            else{
                a.at(n)++;
                s=n;
            }
        }
        cout<<1000000;
    }
    return 0;
}