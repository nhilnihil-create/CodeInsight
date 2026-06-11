#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int> vi;
const int mod = 1000000007;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    if(n==1 ){
        if(m>2){
            cout<<m-2<<endl;
        }
        else if(m==2){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
        return 0;
    }
     if(m==1 ){
        if(n>2){
            cout<<n-2<<endl;
        }
        else if(n==2){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
        return 0;
    }
    n = n-2;
    m = m-2;
    if(n<0){
        n=0;
    }
    if(m<0){
        m=0;
    }
    cout<<n*m<<endl;



}






