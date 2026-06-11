#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define modbig (10*10*10*10*10*10*10*10*10+7)
using namespace std;

int main(){
  ll n,check=0;
  cin>>n;
  for(ll h=1;h<=3500;h++){
    for(ll b=1;b<=3500;b++){
      if(4*h*b>n*(h+b) && (n*h*b)%(4*h*b-n*(h+b))==0){
        int w=(n*h*b)/(4*h*b-n*(h+b));
        cout<<h<<" "<<b<<" "<<w;
        check=1;
        break;
      }
    }
    if(check==1)break;
  }
}
