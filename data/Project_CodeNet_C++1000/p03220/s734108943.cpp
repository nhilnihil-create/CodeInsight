#include<bits/stdc++.h>
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
using namespace std;
#define ll long long
#define MX 1e9
int main(){
    int n;
    cin>>n;
     double t, a;
    cin>>t>>a;


    double ans = 2e9;
    int in=0;

    for(int i=1;i<=n;i++){
        double x;
        cin>>x;
        double res = t- x * 0.006;

        if(abs(res-a) < ans){
            ans = abs(res-a);
            in = i;
        }
    }
    cout<<in<<endl;


 return 0;
}
