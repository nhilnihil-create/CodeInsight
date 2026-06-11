#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    
    int n;
    cin>>n;
    int sum = 0;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)sum+=a[i];
    int dif = 1e9;
    for(int i=0;i<n;i++)chmin(dif,abs(sum-n*a[i]));
    for(int i=0;i<n;i++){
        if(abs(sum-n*a[i]) == dif){
            cout << i << endl;
            return 0;
        }
    }
}