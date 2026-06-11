#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <utility>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
using P = pair<int,int>;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int main(){
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll> bit(40,0);
    for(int i=0;i<n;i++){
        for(int j=39;j>=0;j--){
            if(a[i]>=(ll)pow(2,j)){
                bit[j]++;
                a[i]-=(ll)pow(2,j);
            }
        }
    }
    ll ret=0;
    vector<ll> s(40),t(40);
    s[0]=max(bit[0],n-bit[0]);
    for(int i=1;i<40;i++){
        s[i]=s[i-1]+(ll)pow(2,i)*max(bit[i],n-bit[i]);
    }
    if((k>>39)&1)t[39]=(ll)pow(2,39)*(n-bit[39]);
    else t[39]=(ll)pow(2,39)*bit[39];
    for(int i=38;i>=0;i--){
        if((k>>i)&1)t[i]=t[i+1]+(ll)pow(2,i)*(n-bit[i]);
        else t[i]=t[i+1]+(ll)pow(2,i)*bit[i];
    }
    ret=t[0];
    for(int i=0;i<40;i++){
        if((k>>i)&1){
            ll tmp=0;
            tmp+=(ll)pow(2,i)*bit[i];
            if(i+1<40)tmp+=t[i+1];
            if(i-1>=0)tmp+=s[i-1];
            chmax(ret,tmp);
        }
    }
    cout<<ret<<endl;
}