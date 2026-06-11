#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <cctype>
//小文字を大文字 c-0x20;


#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define vvll(z,a,b) vector<vector<ll>>z(a,vector<ll>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) c.begin(),c.end()
#define fix(k) fixed<<setprecision(k)
#define PI 3.141592653589793
using namespace std;


int hantei(int a,int b,int k){
    vi youso(100);
    int w=0;
    for(int j=1;j<=a;j++){
        if((a%j==0)&&(b%j==0)){
            youso.at(w)=j;
            




            w++;
        }
    }
    
    return youso.at(w-k);
   
}

int main(){
    int a,b,k;cin>>a>>b>>k;
    int x=hantei(a,b,k);
    cout<<x<<endl;
}
